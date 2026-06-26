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

void Service_Dicom::slot_set_sp_Dicom_Reader(vtkSmartPointer<vtkDICOMImageReader> set)
{
    this->sp_Dicom_Reader = set;
    return;
}

void Service_Dicom::dicomFile_Load(const QString path, const path_Type type)
{
    QtConcurrent::run([this, path, type]() {
        vtkSmartPointer<vtkDICOMImageReader> sp_reader = vtkSmartPointer<vtkDICOMImageReader>::New();

        if (type == path_Type::FILE_PATH)
        {
            sp_reader->SetFileName(path.toStdString().c_str());
        }
        else if (type == path_Type::DIR_PATH)
        {
            sp_reader->SetDirectoryName(path.toStdString().c_str());
        }

        sp_reader->Update();

        QMetaObject::invokeMethod(this,
                                  "slot_set_sp_Dicom_Reader",
                                  Qt::QueuedConnection,
                                  Q_ARG(vtkSmartPointer<vtkDICOMImageReader>, sp_reader));

        vtkSmartPointer<vtkImageData> sp_ret = vtkSmartPointer<vtkImageData>::New();

        sp_ret->DeepCopy(sp_reader->GetOutput());

        QMetaObject::invokeMethod(this,
                                  "sig_dicomFile_Load_To_VM_dicom",
                                  Qt::QueuedConnection,
                                  Q_ARG(vtkSmartPointer<vtkImageData>, sp_ret));
        // emit this->sig_dicomFile_Load_To_VM_dicom(sp_ret);
        return;
    });

    return;
}
