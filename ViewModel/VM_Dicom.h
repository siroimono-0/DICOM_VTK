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

    //=====================Get_STORE=====================
    //=====================Get_STORE=====================
    vtkSmartPointer<vtkImageData> get_store_image();
    //=====================Get_STORE=====================
    //=====================Get_STORE=====================

public slots:
    void slot_dicomFile_Load_From_Svc(vtkSmartPointer<vtkImageData> ret);

signals:

private:
    I_Dicom_Common *p_i_Dicom_common = nullptr;
    Store_Dicom *p_st_Dicom = nullptr;
};

#endif // VM_DICOM_H
