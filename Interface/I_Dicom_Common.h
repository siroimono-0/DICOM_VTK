#ifndef I_DICOM_COMMON_H
#define I_DICOM_COMMON_H
#include <QString>
#include "../Common.h"
#include <vtkCallbackCommand.h>
#include <vtkCommand.h>
#include <vtkDICOMImageReader.h>
#include <vtkSmartPointer.h>

class I_Dicom_Common
{
public:
    virtual ~I_Dicom_Common() = default;

    virtual void dicomFile_Load(const QString path, const path_Type type) = 0;
};

#endif // I_DICOM_COMMON_H
