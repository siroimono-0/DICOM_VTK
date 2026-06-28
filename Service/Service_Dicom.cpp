#include "Service_Dicom.h"
#include "./WK_Dicom_1.h"

Service_Dicom::Service_Dicom(QObject *parent)
    : QObject{parent}
{
    this->init();
}

void Service_Dicom::init()
{
    // this->sp_Dicom_Reader = vtkSmartPointer<vtkDICOMImageReader>::New();

    return;
}

/*
void Service_Dicom::slot_set_sp_Dicom_Reader(vtkSmartPointer<vtkDICOMImageReader> set)
{
    this->sp_Dicom_Reader = set;
    return;
}
*/

void Service_Dicom::slot_create_Mp_DicomMetaDat_From_WK(dicomMetaDataMap ret)
{
    emit this->sig_create_Mp_DicomMetaDat_To_VM_Dicom(std::move(ret));
    return;
}

void Service_Dicom::dicomFile_Load(const QString path, const path_Type type)
{
    QThread* th = new QThread;
    WK_Dicom_1* wk = new WK_Dicom_1;

    // wk->set_Service_Dicom(this);
    wk->set_path(path);
    wk->set_type(type);

    wk->moveToThread(th);

    //=================== Thread, WK 생명주기 ===================
    //=================== Thread, WK 생명주기 ===================
    connect(th, &QThread::started, wk, &WK_Dicom_1::run_DicomFile);
    connect(wk, &WK_Dicom_1::sig_wk_End, th, &QThread::quit);
    connect(th, &QThread::finished, wk, &WK_Dicom_1::deleteLater);
    connect(th, &QThread::finished, th, &QThread::deleteLater);
    //=================== Thread, WK 생명주기 ===================
    //=================== Thread, WK 생명주기 ===================

    //=================== Service <> WK ===================
    //=================== Service <> WK ===================
    connect(wk,
            &WK_Dicom_1::sig_DicomFile_Finished,
            this,
            &Service_Dicom::sig_dicomFile_Load_To_VM_dicom);

    connect(wk,
            &WK_Dicom_1::sig_create_Mp_DicomMetaData_Finished,
            this,
            &Service_Dicom::slot_create_Mp_DicomMetaDat_From_WK);

    connect(wk,
            &WK_Dicom_1::sig_makeDicomImage_Finished,
            this,
            &Service_Dicom::sig_makeDicomImage_To_VM_Dicom);
    //=================== Service <> WK ===================
    //=================== Service <> WK ===================

    th->start();
    return;
}
