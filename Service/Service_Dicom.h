#ifndef SERVICE_DICOM_H
#define SERVICE_DICOM_H

#include <QObject>
#include <QtConcurrent>
#include "../Common.h"
#include "../Interface/I_Dicom_Common.h"
#include <vtkCallbackCommand.h>
#include <vtkCommand.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageData.h>
#include <vtkSmartPointer.h>

class Service_Dicom : public QObject, public I_Dicom_Common
{
    Q_OBJECT
public:
    explicit Service_Dicom(QObject *parent = nullptr);

    void init();

    void dicomFile_Load(const QString path, const path_Type type) override;

public slots:
    void slot_set_sp_Dicom_Reader(vtkSmartPointer<vtkDICOMImageReader> set);

signals:
    void sig_dicomFile_Load_To_VM_dicom(vtkSmartPointer<vtkImageData> sp_img);

private:
    vtkSmartPointer<vtkDICOMImageReader> sp_Dicom_Reader;
};
Q_DECLARE_METATYPE(vtkSmartPointer<vtkDICOMImageReader>);

#endif // SERVICE_DICOM_H
