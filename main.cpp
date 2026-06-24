#include "AppContext.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vtkObject::GlobalWarningDisplayOff(); // VTK Warning 출력 끄기

    qRegisterMetaType<vtkSmartPointer<vtkImageData>>("vtkSmartPointer<vtkImageData>");
    AppContext appcontext;
    appcontext.get_p_v_Dicom()->show();
    return a.exec();
}
