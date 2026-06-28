#include "WK_Dicom_1.h"

WK_Dicom_1::WK_Dicom_1(QObject *parent)
    : QObject{parent}
{
    this->init();
}

WK_Dicom_1::~WK_Dicom_1()
{
    qDebug() << "WK End";
    return;
}
/*
void WK_Dicom_1::set_Service_Dicom(Service_Dicom *set)
{
    this->p_svc_Dicom = set;
    return;
}*/

void WK_Dicom_1::init()
{
    this->sp_Dicom_Reader = vtkSmartPointer<vtkDICOMImageReader>::New();
    return;
}

void WK_Dicom_1::set_path(const QString set)
{
    this->path = set;
    return;
}

void WK_Dicom_1::set_type(const path_Type set)
{
    this->type = set;
    return;
}

QString WK_Dicom_1::readTag(DcmDataset *dataset, const DcmTagKey &tag)
{
    if (dataset == nullptr)
        return "-";

    OFString value;

    // 문자열 태그를 읽음
    OFCondition status = dataset->findAndGetOFStringArray(tag, value);

    if (status.good())
        return QString::fromLocal8Bit(value.c_str()).trimmed();

    return "-";
}

dicomMetaData WK_Dicom_1::read_DicomMetaData(const QString &filePath, const QString &fileName)
{
    dicomMetaData meta;

    DcmFileFormat fileFormat;

    OFCondition status = fileFormat.loadFile(filePath.toLocal8Bit().constData());

    if (status.bad())
        return meta;

    DcmDataset *dataset = fileFormat.getDataset();

    // Patient
    meta.patientName = readTag(dataset, DCM_PatientName);
    meta.patientID = readTag(dataset, DCM_PatientID);
    meta.patientBirthDate = readTag(dataset, DCM_PatientBirthDate);
    meta.patientSex = readTag(dataset, DCM_PatientSex);
    meta.patientAge = readTag(dataset, DCM_PatientAge);
    meta.patientWeight = readTag(dataset, DCM_PatientWeight);
    meta.patientAddress = readTag(dataset, DCM_PatientAddress);

    // Study
    meta.studyDate = readTag(dataset, DCM_StudyDate);
    meta.studyTime = readTag(dataset, DCM_StudyTime);
    meta.studyID = readTag(dataset, DCM_StudyID);
    meta.studyDescription = readTag(dataset, DCM_StudyDescription);

    // Series
    meta.seriesDate = readTag(dataset, DCM_SeriesDate);
    meta.seriesTime = readTag(dataset, DCM_SeriesTime);
    meta.seriesDescription = readTag(dataset, DCM_SeriesDescription);
    meta.seriesNumber = readTag(dataset, DCM_SeriesNumber);
    meta.seriesInstanceUID = readTag(dataset, DCM_SeriesInstanceUID);

    // Equipment / Institution
    meta.institutionName = readTag(dataset, DCM_InstitutionName);
    meta.manufacturerModelName = readTag(dataset, DCM_ManufacturerModelName);

    // Acquisition
    meta.acquisitionDate = readTag(dataset, DCM_AcquisitionDate);
    meta.acquisitionTime = readTag(dataset, DCM_AcquisitionTime);

    // Image / Slice
    meta.sliceThickness = readTag(dataset, DCM_SliceThickness);
    meta.sliceLocation = readTag(dataset, DCM_SliceLocation);
    meta.instanceNumber = readTag(dataset, DCM_InstanceNumber);

    // Modality
    meta.modality = readTag(dataset, DCM_Modality);

    meta.filePath = filePath;
    meta.fileName = fileName;

    return meta;
}

void WK_Dicom_1::create_Mp_DicomMetaData()
{
    // this->vec_Path.clear();
    this->mp_DicomMetaData.clear();
    this->vec_DicomMetaData.clear();

    if (this->type == path_Type::FILE_PATH)
    {
    }
    else if (this->type == path_Type::DIR_PATH)
    {
        QDir dir;
        dir.setPath(this->path);

        QFileInfoList fileList = dir.entryInfoList({"*"}, QDir::Files);
        if (fileList.isEmpty())
        {
            return;
        }

        for (auto &v : fileList)
        {
            // 정상 파일 필터
            if (!v.exists() || !v.isFile() || !v.isReadable())
            {
                continue;
            }

            // DcmFileFormat에 사용할 수 있도록 변환
            QByteArray localPath = QFile::encodeName(v.absoluteFilePath());

            DcmFileFormat dicomFile;

            // DICOM 파일 맞는지 확인
            OFCondition status = dicomFile.loadFile(localPath.constData(),
                                                    EXS_Unknown,
                                                    EGL_noChange,
                                                    DCM_MaxReadLength,
                                                    ERM_autoDetect);
            if (status.bad())
            {
                continue;
            }

            DcmDataset *dataset = dicomFile.getDataset();

            if (dataset == nullptr)
            {
                continue;
            }

            // DICOM 파일만 push
            // DICOM 메타데이터 추출
            dicomMetaData meta = this->read_DicomMetaData(v.absoluteFilePath(), v.fileName());

            this->mp_DicomMetaData[meta.seriesInstanceUID].push_back(meta);
            // this->vec_DicomMetaData.push_back(meta);
            // this->vec_Path.push_back(v.absoluteFilePath());
        }

        for (auto &v : mp_DicomMetaData)
        {
            std::sort(v.begin(), v.end(), [](const dicomMetaData &d1, const dicomMetaData &d2) {
                return d1.instanceNumber.toInt() < d2.instanceNumber.toInt();
            });
            /*
            for (auto &vv : v)
            {
                qDebug() << vv.instanceNumber;
            }*/
        }

        int mmax = -1;

        for (auto &v : mp_DicomMetaData)
        {
            if (mmax < v.size())
            {
                mmax = v.size();
                this->cur_seriesInstanceUID = v.front().seriesInstanceUID;
            }

            for (int i = 0; i < v.size(); i++)
            {
                // vtkResliceImageViewer의 SetSlice index는
                // 현재 데이터에서 반대 방향이므로 변환
                // v[i].number = i;
                v[i].SliceIndex = v.size() - 1 - i;
            }
        }
    }

    return;
}

QString WK_Dicom_1::makeDicomImage(const QString seriesInstanceUID)
{
    QTemporaryDir tmpDir;
    QString tmpDirPath = tmpDir.path();
    qDebug() << tmpDirPath;

    // QString seriesInstanceUID = this->cur_seriesInstanceUID;
    // seriesInstanceUID.replace(".", "_");
    QString dirPath = tmpDirPath + "/DICOM_SERIES_" + cur_seriesInstanceUID;

    QDir dir(tmpDirPath);
    if (dir.exists())
    {
        dir.removeRecursively();
    }

    dir.mkpath(dirPath);

    auto it_copy_Series = this->mp_DicomMetaData.find(seriesInstanceUID);

    if (it_copy_Series == this->mp_DicomMetaData.end())
    {
        qDebug() << "it_copy_Series == this->mp_DicomMetaData.end()";
        return "";
    }

    for (auto &metaData : it_copy_Series.value())
    {
        QString dstPath = dirPath + "/" + metaData.fileName;
        bool ret = QFile::copy(metaData.filePath, dstPath);
        if (ret)
        {
            // qDebug() << "copy " << metaData.fileName;
        }
        else
        {
            // qDebug() << " ERR";
        }
    }

    this->sp_Dicom_Reader->SetDirectoryName(dirPath.toStdString().c_str());
    this->sp_Dicom_Reader->Update();

    vtkSmartPointer<vtkImageData> sp_ret = vtkSmartPointer<vtkImageData>::New();

    sp_ret->DeepCopy(this->sp_Dicom_Reader->GetOutput());
    this->mp_DicomImage[seriesInstanceUID] = sp_ret;

    return "";
}

void WK_Dicom_1::run_DicomFile()
{
    qDebug() << "WK Start";
    // vtkSmartPointer<vtkDICOMImageReader> sp_reader = vtkSmartPointer<vtkDICOMImageReader>::New();

    if (this->type == path_Type::FILE_PATH)
    {
        this->sp_Dicom_Reader->SetFileName(path.toStdString().c_str());
    }
    else if (this->type == path_Type::DIR_PATH)
    {
        this->create_Mp_DicomMetaData();

        for (auto it = this->mp_DicomMetaData.begin(); it != this->mp_DicomMetaData.end(); it++)
        {
            this->makeDicomImage(it.key());
        }

        emit this->sig_create_Mp_DicomMetaData_Finished(std::move(this->mp_DicomMetaData));
    }
    emit this->sig_makeDicomImage_Finished(this->mp_DicomImage);

    emit this->sig_DicomFile_Finished(this->mp_DicomImage[this->cur_seriesInstanceUID],
                                      this->cur_seriesInstanceUID);

    emit this->sig_wk_End();
    return;
}
