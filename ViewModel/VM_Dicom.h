#ifndef VM_DICOM_H
#define VM_DICOM_H

#include <QObject>
#include "../Common.h"
#include "../Interface/I_Dicom_Common.h"
#include "../Store/Store_Dicom.h"

class VM_Dicom : public QObject
{
    Q_OBJECT
public:
    explicit VM_Dicom(I_Dicom_Common *i_dicom_common,
                      Store_Dicom *st_Dicom,
                      QObject *parent = nullptr);

    void dicomFile_Load(const QString path, const path_Type type);
    //==================== Set_STORE ====================
    //==================== Set_STORE ====================
    void set_Store_ImageData_UID(const QString UID);
    void set_Store_seriesInstanceUID(const QString UID);
    //==================== Set_STORE ====================
    //==================== Set_STORE ====================

    //=====================Get_STORE=====================
    //=====================Get_STORE=====================
    vtkSmartPointer<vtkImageData> get_store_image();
    dicomMetaDataMap get_Store_DicomMetaMap();
    QString get_Store_seriesInstanceUID();
    //=====================Get_STORE=====================
    //=====================Get_STORE=====================

public slots:
    void slot_dicomFile_Load_From_Svc(vtkSmartPointer<vtkImageData> ret, QString uid);

    void slot_create_Mp_DicomMetaDat_From_Svc(dicomMetaDataMap ret);

    void slot_makeDicomImage_From_Svc(dicomImageDataMap ret);

signals:

private:
    I_Dicom_Common *p_i_Dicom_common = nullptr;
    Store_Dicom *p_st_Dicom = nullptr;
};

#endif // VM_DICOM_H
