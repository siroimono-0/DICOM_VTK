#include "VM_Dicom.h"

VM_Dicom::VM_Dicom(I_Dicom_Common *i_dicom_common, Store_Dicom *st_Dicom, QObject *parent)
    : QObject{parent}
{
    this->p_i_Dicom_common = i_dicom_common;
    this->p_st_Dicom = st_Dicom;
}
void VM_Dicom::set_Store_seriesInstanceUID(const QString UID)
{
    this->p_st_Dicom->set_seriesInstanceUID(UID);
    return;
}

void VM_Dicom::set_Store_ImageData_UID(const QString UID)
{
    this->p_st_Dicom->set_sp_image_UID(UID);
    return;
}

QString VM_Dicom::get_Store_seriesInstanceUID()
{
    return this->p_st_Dicom->get_seriesInstanceUID();
}

void VM_Dicom::slot_makeDicomImage_From_Svc(dicomImageDataMap ret)
{
    this->p_st_Dicom->set_mp_Image(ret);
    return;
}

dicomMetaDataMap VM_Dicom::get_Store_DicomMetaMap()
{
    return this->p_st_Dicom->get_mp_DicomMetaData();
}

void VM_Dicom::dicomFile_Load(const QString path, const path_Type type)
{
    this->p_i_Dicom_common->dicomFile_Load(path, type);
    return;
}

void VM_Dicom::slot_dicomFile_Load_From_Svc(vtkSmartPointer<vtkImageData> ret, QString uid)
{
    this->p_st_Dicom->set_sp_image(ret);
    this->p_st_Dicom->set_seriesInstanceUID(uid);
    return;
}

vtkSmartPointer<vtkImageData> VM_Dicom::get_store_image()
{
    return this->p_st_Dicom->get_sp_image();
}

void VM_Dicom::slot_create_Mp_DicomMetaDat_From_Svc(QMap<QString, QVector<dicomMetaData>> ret)
{
    this->p_st_Dicom->set_mp_DicomMetaData(ret);
    return;
}
