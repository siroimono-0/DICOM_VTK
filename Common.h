#ifndef COMMON_H
#define COMMON_H

#include <vtkSmartPointer.h>
// class vtkSmartPointer;
class vtkLineSource;
class vtkPolyDataMapper;
class vtkActor;

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

#endif // COMMON_H
