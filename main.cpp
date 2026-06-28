#include "AppContext.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vtkObject::GlobalWarningDisplayOff(); // VTK Warning 출력 끄기

    qRegisterMetaType<vtkSmartPointer<vtkImageData>>("vtkSmartPointer<vtkImageData>");
    qRegisterMetaType<vtkSmartPointer<vtkDICOMImageReader>>("vtkSmartPointer<vtkDICOMImageReader>");
    qRegisterMetaType<dicomMetaDataVec>("dicomMetaDataVec");
    qRegisterMetaType<dicomMetaDataMap>("dicomMetaDataMap");

    AppContext appcontext;
    appcontext.get_p_v_Dicom()->show();
    return a.exec();
}
