#ifndef SERVICE_DICOM_H
#define SERVICE_DICOM_H

#include <QObject>
#include <QThread>
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
    // void slot_set_sp_Dicom_Reader(vtkSmartPointer<vtkDICOMImageReader> set);

    // move로 이동하기위해 중간 값 받는 다리
    void slot_create_Mp_DicomMetaDat_From_WK(dicomMetaDataMap ret);

signals:
    void sig_dicomFile_Load_To_VM_dicom(vtkSmartPointer<vtkImageData> sp_img);
    void sig_create_Mp_DicomMetaDat_To_VM_Dicom(dicomMetaDataMap mp);

private:
    // vtkSmartPointer<vtkDICOMImageReader> sp_Dicom_Reader;
};

#endif // SERVICE_DICOM_H
