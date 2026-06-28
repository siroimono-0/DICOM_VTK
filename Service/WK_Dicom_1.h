#ifndef WK_DICOM_1_H
#define WK_DICOM_1_H

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QObject>
#include <QTemporaryDir>
#include "../Common.h"
#include "./Service_Dicom.h"
#include <algorithm>

class WK_Dicom_1 : public QObject
{
    Q_OBJECT
public:
    explicit WK_Dicom_1(QObject *parent = nullptr);
    ~WK_Dicom_1();

    void init();
    // void set_Service_Dicom(Service_Dicom* set);
    void set_path(const QString set);
    void set_type(const path_Type set);
    void run_DicomFile();

    void create_Mp_DicomMetaData();
    QString readTag(DcmDataset *dataset, const DcmTagKey &tag);
    dicomMetaData read_DicomMetaData(const QString &filePath, const QString &fileName);
    // static bool dicom_sotr(dicomMetaData d1, dicomMetaData d2);
    // void compare_DicomFile();
    QString makeDicomImage(const QString seriesInstanceUID);

public slots:

signals:
    void sig_wk_End();
    void sig_DicomFile_Finished(vtkSmartPointer<vtkImageData> sp_img, QString uid);
    void sig_create_Mp_DicomMetaData_Finished(dicomMetaDataMap mp_DicomMetaData);
    void sig_makeDicomImage_Finished(dicomImageDataMap mp_DicomImage);

private:
    // Service_Dicom* p_svc_Dicom = nullptr;

    QString path;
    path_Type type;
    vtkSmartPointer<vtkDICOMImageReader> sp_Dicom_Reader;
    // QVector<QString> vec_Path;

    dicomMetaDataVec vec_DicomMetaData;
    // QVector<dicomMetaData> vec_DicomMetaData;

    dicomMetaDataMap mp_DicomMetaData;
    // QMap<QString, QVector<dicomMetaData>> mp_DicomMetaData;

    QString cur_seriesInstanceUID;

    dicomImageDataMap mp_DicomImage;
    // QMap<QString, vtkSmartPointer<vtkImageData>>
};

#endif // WK_DICOM_1_H
