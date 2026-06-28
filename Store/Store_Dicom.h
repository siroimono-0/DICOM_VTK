#ifndef STORE_DICOM_H
#define STORE_DICOM_H

#include <QObject>
#include "../Common.h"
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
    dicomMetaDataMap get_mp_DicomMetaData();
    QString get_seriesInstanceUID();

    //=======================GET=======================
    //=======================GET=======================

    //=======================SET=======================
    //=======================SET=======================
    void set_sp_image(vtkSmartPointer<vtkImageData> set);
    void set_sp_image_UID(const QString UID);
    void set_mp_DicomMetaData(dicomMetaDataMap set);
    void set_mp_Image(dicomImageDataMap set);
    void set_seriesInstanceUID(const QString set);

    //=======================SET=======================
    //=======================SET=======================

public slots:

signals:
    //=======================CHANGE=======================
    //=======================CHANGE=======================
    void sig_sp_image_change();
    void sig_mp_DicomMetaData_change();
    //=======================CHANGE=======================
    //=======================CHANGE=======================

private:
    vtkSmartPointer<vtkImageData> sp_image;
    QString seriesInstanceUID;

    dicomImageDataMap mp_Image;
    // QMap<QString,vtkSmartPointer<vtkImageData>>;

    dicomMetaDataMap mp_DicomMetaData;
};

#endif // STORE_DICOM_H
