#include "Service_Dicom.h"

Service_Dicom::Service_Dicom(QObject *parent)
    : QObject{parent}
{
    this->init();
}

void Service_Dicom::init()
{
    this->sp_Dicom_Reader = vtkSmartPointer<vtkDICOMImageReader>::New();

    return;
}

void Service_Dicom::dicomFile_Load(const QString path, const path_Type type)
{
    QtConcurrent::run([=]() {
        if (type == path_Type::FILE_PATH)
        {
            this->sp_Dicom_Reader->SetFileName(path.toStdString().c_str());
        }
        else if (type == path_Type::DIR_PATH)
        {
            this->sp_Dicom_Reader->SetDirectoryName(path.toStdString().c_str());
        }

        this->sp_Dicom_Reader->Update();
        vtkSmartPointer<vtkImageData> sp_ret = vtkSmartPointer<vtkImageData>::New();

        sp_ret->DeepCopy(this->sp_Dicom_Reader->GetOutput());

        emit this->sig_dicomFile_Load_To_VM_dicom(sp_ret);
        return;
    });

    return;
}
