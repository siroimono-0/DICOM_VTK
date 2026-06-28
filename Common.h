#ifndef COMMON_H
#define COMMON_H

#include <QMap>
#include <QMetaType>
#include <QObject>
#include <QString>
#include <QVector>
#include <dcmtk/dcmdata/dcdeftag.h>
#include <dcmtk/dcmdata/dctk.h>
#include <vtkDICOMImageReader.h>
#include <vtkSmartPointer.h>

// class vtkSmartPointer;
class vtkLineSource;
class vtkPolyDataMapper;
class vtkActor;

enum treeItem_DataType {
    Role_Number = Qt::UserRole + 1,
    // Patient
    Role_patientName,
    Role_patientID,
    Role_patientBirthDate,
    Role_patientSex,
    Role_patientAge,
    Role_patientWeight,
    Role_patientAddress,

    // Study
    Role_studyDate,
    Role_studyTime,
    Role_studyID,
    // Modality
    Role_modality,
    Role_studyDescription,

    // Series
    Role_seriesDate,
    Role_seriesTime,
    Role_seriesDescription
};
enum class path_Type { FILE_PATH, DIR_PATH };

enum class vtkResliceImageView_Type { AXIAL, CORONAL, SAGITTAL };

enum class imageRoll_Type { LEFT, RIGHT };

enum class imageFlip_Type { VERTICAL, HORIZONTAL };

enum class crossHairLines_Type { AXIAL, CORONAL, SAGITTAL };

struct crossHairLines
{
    vtkSmartPointer<vtkLineSource> line_1;
    vtkSmartPointer<vtkLineSource> line_2;

    vtkSmartPointer<vtkPolyDataMapper> mapper_1;
    vtkSmartPointer<vtkPolyDataMapper> mapper_2;

    vtkSmartPointer<vtkActor> actor_1;
    vtkSmartPointer<vtkActor> actor_2;
};

struct dicomMetaData
{
    // Patient
    QString patientName;
    QString patientID;
    QString patientBirthDate;
    QString patientSex;
    QString patientAge;
    QString patientWeight;
    QString patientAddress;

    // Study
    QString studyDate;
    QString studyTime;
    QString studyID;
    QString studyDescription;

    // Series
    QString seriesDate;
    QString seriesTime;
    QString seriesDescription;
    QString seriesNumber;
    QString seriesInstanceUID; // 촬영 묶음

    // Equipment / Institution
    QString institutionName;
    QString manufacturerModelName;

    // Acquisition
    QString acquisitionDate;
    QString acquisitionTime;

    // Image / Slice
    QString sliceThickness;
    QString sliceLocation;
    QString instanceNumber;

    // Modality
    QString modality;

    QString filePath;
    QString fileName;

    int SliceIndex;

    // 정렬용
    // QString imagePositionPatient;
    // QString imageOrientationPatient;
};

using dicomMetaDataVec = QVector<dicomMetaData>;
using dicomMetaDataMap = QMap<QString, dicomMetaDataVec>;
using dicomImageDataMap = QMap<QString, vtkSmartPointer<vtkImageData>>;

Q_DECLARE_METATYPE(vtkSmartPointer<vtkDICOMImageReader>);
Q_DECLARE_METATYPE(dicomMetaDataVec);
Q_DECLARE_METATYPE(dicomMetaDataMap);

#endif // COMMON_H
