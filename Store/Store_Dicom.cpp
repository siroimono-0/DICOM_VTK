#include "Store_Dicom.h"

Store_Dicom::Store_Dicom(QObject *parent)
    : QObject{parent}
{
    this->init();
}

void Store_Dicom::init()
{
    this->sp_image = vtkSmartPointer<vtkImageData>::New();
}

vtkSmartPointer<vtkImageData> Store_Dicom::get_sp_image()
{
    return this->sp_image;
}

void Store_Dicom::set_sp_image(vtkSmartPointer<vtkImageData> set)
{
    this->sp_image = set;
    emit this->sig_sp_image_change();
    return;
}
