#include "Store_Dicom.h"

Store_Dicom::Store_Dicom(QObject *parent)
    : QObject{parent}
{
    this->init();
}

void Store_Dicom::set_mp_Image(dicomImageDataMap set)
{
    this->mp_Image = set;
    return;
}

QString Store_Dicom::get_seriesInstanceUID()
{
    return this->seriesInstanceUID;
}

void Store_Dicom::set_seriesInstanceUID(const QString set)
{
    this->seriesInstanceUID = set;
    return;
}

void Store_Dicom::init()
{
    this->sp_image = vtkSmartPointer<vtkImageData>::New();
}

vtkSmartPointer<vtkImageData> Store_Dicom::get_sp_image()
{
    return this->sp_image;
}

dicomMetaDataMap Store_Dicom::get_mp_DicomMetaData()
{
    return this->mp_DicomMetaData;
}

void Store_Dicom::set_sp_image_UID(const QString UID)
{
    this->sp_image = this->mp_Image[UID];
    emit this->sig_sp_image_change();

    return;
}

void Store_Dicom::set_sp_image(vtkSmartPointer<vtkImageData> set)
{
    this->sp_image = set;
    emit this->sig_sp_image_change();
    return;
}

void Store_Dicom::set_mp_DicomMetaData(dicomMetaDataMap set)
{
    this->mp_DicomMetaData = set;
    emit this->sig_mp_DicomMetaData_change();
    return;
}
