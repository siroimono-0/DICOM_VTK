#ifndef VIEW_DICOM_H
#define VIEW_DICOM_H

#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QResizeEvent>
#include <QShowEvent>
#include <QSignalBlocker>
#include <QTimer>
#include <QVTKOpenGLNativeWidget.h>
#include "../CallBack_VtkCommand.h"
#include "../ViewModel/VM_Dicom.h"
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkDICOMImageReader.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkImageActor.h>
#include <vtkImageViewer2.h>
#include <vtkNew.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkResliceCursor.h>
#include <vtkResliceCursorActor.h>
#include <vtkResliceCursorLineRepresentation.h>
#include <vtkResliceCursorPolyDataAlgorithm.h>
#include <vtkResliceCursorRepresentation.h>
#include <vtkResliceCursorWidget.h>
#include <vtkResliceImageViewer.h>
#include <vtkSmartPointer.h>

namespace Ui {
class View_Dicom;
}

class View_Dicom : public QMainWindow
{
    Q_OBJECT

public:
    explicit View_Dicom(VM_Dicom *vm_Dicom, QWidget *parent = nullptr);
    ~View_Dicom();

    void showEvent(QShowEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

    void init_connection();
    void init_AddObserver();
    void init_Render_Windo();
    void init_Reslice_Viewr();
    void init_UI_First();

    void set_Color_Window_Level();
    void set_ui_slider();
    void set_ui_slider_vtkCommand(const vtkResliceImageView_Type type);

    void fix_ViewScale_Width(vtkResliceImageViewer *p_Reslice_Viewer,
                             QVTKOpenGLNativeWidget *p_UI_Widget,
                             const vtkResliceImageView_Type type);

    void roll_View(vtkResliceImageViewer *p_Reslice_Viewer, const imageRoll_Type roll_Type);

    void flip_View(vtkResliceImageViewer *p_Reslice_Viewer, const imageFlip_Type flip_Type);

public slots:
    //======================UI SLOT=====================
    void slot_Action_FileOpen_Clicked();
    void slot_Action_DirectoryOpen_Clicked();

    void slot_DicomFile_Reload_From_Store();
    void slot_MainWindow_Resize();

    void slot_Axial_RollBtn_Left_Clicked();
    void slot_Axial_RollBtn_Right_Clicked();
    void slot_Coronal_RollBtn_Left_Clicked();
    void slot_Coronal_RollBtn_Right_Clicked();
    void slot_Sagittal_RollBtn_Left_Clicked();
    void slot_Sagittal_RollBtn_Right_Clicked();

    void slot_Axial_FlipBtn_Horizontal_Clicked();
    void slot_Axial_FlipBtn_Vertical_Clicked();
    void slot_Coronal_FlipBtn_Horizontal_Clicked();
    void slot_Coronal_FlipBtn_Vertical_Clicked();
    void slot_Sagittal_FlipBtn_Horizontal_Clicked();
    void slot_Sagittal_FlipBtn_Vertical_Clicked();
signals:
    void sig_MainWindow_Resize();

private:
    Ui::View_Dicom *ui;

    VM_Dicom *p_vm_Dicom = nullptr;

    //========================== VTK ==========================
    //========================== VTK ==========================
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> sp_Axial_Render_Windo = nullptr;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> sp_Coronal_Render_Windo = nullptr;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> sp_Sagittal_Render_Windo = nullptr;

    vtkSmartPointer<vtkResliceImageViewer> sp_Axial_Viewer = nullptr;
    vtkSmartPointer<vtkResliceImageViewer> sp_Coronal_Viewer = nullptr;
    vtkSmartPointer<vtkResliceImageViewer> sp_Sagittal_Viewer = nullptr;
    //========================== VTK ==========================
    //========================== VTK ==========================

    //======================== Observer ========================
    //======================== Observer ========================
    vtkSmartPointer<CallBack_VtkCommand> sp_Axial_Viewer_Command = nullptr;
    vtkSmartPointer<CallBack_VtkCommand> sp_Coronal_Viewer_Command = nullptr;
    vtkSmartPointer<CallBack_VtkCommand> sp_Sagittal_Viewer_Command = nullptr;
    //======================== Observer ========================
    //======================== Observer ========================
};

#endif // VIEW_DICOM_H
