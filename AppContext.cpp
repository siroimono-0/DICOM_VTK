#include "AppContext.h"

AppContext::AppContext(QObject *parent)
    : QObject{parent}
{
    this->init_p_st_Dicom();
    this->init_p_svc_Dicom();
    this->init_p_vm_Dicom();
    this->init_p_v_Dicom();

    this->init_connect_p_svc_Dicom_To_p_vm_Dicom();
    this->init_connect_p_st_Dicom_To_p_v_Dicom();
}

AppContext::~AppContext()
{
    // ViewDicom QWidget상속이라 부모설정 불가 직접 delete
    this->p_v_Dicom->deleteLater();
}

View_Dicom *AppContext::get_p_v_Dicom()
{
    return this->p_v_Dicom;
}

void AppContext::init_p_st_Dicom()
{
    this->p_st_Dicom = new Store_Dicom(this);
    return;
}

void AppContext::init_p_svc_Dicom()
{
    this->p_svc_Dicom = new Service_Dicom(this);
    return;
}

void AppContext::init_p_vm_Dicom()
{
    this->p_vm_Dicom = new VM_Dicom(this->p_svc_Dicom, this->p_st_Dicom, this);
    return;
}

void AppContext::init_p_v_Dicom()
{
    this->p_v_Dicom = new View_Dicom(this->p_vm_Dicom);
    return;
}

void AppContext::init_connect_p_svc_Dicom_To_p_vm_Dicom()
{
    connect(this->p_svc_Dicom,
            &Service_Dicom::sig_dicomFile_Load_To_VM_dicom,
            this->p_vm_Dicom,
            &VM_Dicom::slot_dicomFile_Load_From_Svc);

    connect(this->p_svc_Dicom,
            &Service_Dicom::sig_create_Mp_DicomMetaDat_To_VM_Dicom,
            this->p_vm_Dicom,
            &VM_Dicom::slot_create_Mp_DicomMetaDat_From_Svc);

    connect(this->p_svc_Dicom,
            &Service_Dicom::sig_makeDicomImage_To_VM_Dicom,
            this->p_vm_Dicom,
            &VM_Dicom::slot_makeDicomImage_From_Svc);
    return;
}

void AppContext::init_connect_p_st_Dicom_To_p_v_Dicom()
{
    connect(this->p_st_Dicom,
            &Store_Dicom::sig_sp_image_change,
            this->p_v_Dicom,
            &View_Dicom::slot_DicomFile_Reload_From_Store,
            Qt::DirectConnection);

    connect(this->p_st_Dicom,
            &Store_Dicom::sig_mp_DicomMetaData_change,
            this->p_v_Dicom,
            &View_Dicom::slot_create_Mp_DicomMetaDat_From_Store);

    connect(this->p_st_Dicom,
            &Store_Dicom::sig_First_seriesInstanceUID_To_View_Dicom,
            this->p_v_Dicom,
            &View_Dicom::slot_Set_First_TreeItem_Position_From_Store);

    return;
}
