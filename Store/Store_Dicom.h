#ifndef STORE_DICOM_H
#define STORE_DICOM_H

#include <QObject>
#include <vtkCallbackCommand.h>
#include <vtkCommand.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageData.h>
#include <vtkSmartPointer.h>

class Store_Dicom : public QObject
{
    Q_OBJECT
public:
    explicit Store_Dicom(QObject *parent = nullptr);

    void init();

    //=======================GET=======================
    //=======================GET=======================
    vtkSmartPointer<vtkImageData> get_sp_image();

    //=======================GET=======================
    //=======================GET=======================

    //=======================SET=======================
    //=======================SET=======================
    void set_sp_image(vtkSmartPointer<vtkImageData> set);
    //=======================SET=======================
    //=======================SET=======================

public slots:

signals:
    //=======================CHANGE=======================
    //=======================CHANGE=======================
    void sig_sp_image_change();
    //=======================CHANGE=======================
    //=======================CHANGE=======================

private:
    vtkSmartPointer<vtkImageData> sp_image;
};

#endif // STORE_DICOM_H
