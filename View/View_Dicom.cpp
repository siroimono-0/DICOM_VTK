#include "View_Dicom.h"
#include "./View/ui_View_Dicom.h"

View_Dicom::View_Dicom(VM_Dicom *vm_Dicom, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View_Dicom)
{
    ui->setupUi(this);
    this->p_vm_Dicom = vm_Dicom;

    this->init_UI_First();

    this->init_Render_Windo();
    this->init_connection();

    QIcon icon(":/image/time.svg");
    this->ui->pushButton_1->setIcon(icon);
}

View_Dicom::~View_Dicom()
{
    delete ui;
}

void View_Dicom::flip_View(vtkResliceImageViewer *p_Reslice_Viewer, const imageFlip_Type flip_Type)
{
    if (p_Reslice_Viewer == nullptr)
    {
        return;
    }

    auto render = p_Reslice_Viewer->GetRenderer();
    auto camera = render->GetActiveCamera();

    if (flip_Type == imageFlip_Type::HORIZONTAL)
    {
        camera->Azimuth(180.0);
    }
    else if (flip_Type == imageFlip_Type::VERTICAL)
    {
        camera->Elevation(180.0);
    }

    camera->OrthogonalizeViewUp();
    return;
}

void View_Dicom::slot_Axial_FlipBtn_Horizontal_Clicked()
{
    this->flip_View(this->sp_Axial_Viewer, imageFlip_Type::HORIZONTAL);
    this->fix_ViewScale_Width(this->sp_Axial_Viewer,
                              this->ui->QVTK_axialWidget,
                              vtkResliceImageView_Type::AXIAL);
    return;
}

void View_Dicom::slot_Axial_FlipBtn_Vertical_Clicked()
{
    this->flip_View(this->sp_Axial_Viewer, imageFlip_Type::VERTICAL);
    this->fix_ViewScale_Width(this->sp_Axial_Viewer,
                              this->ui->QVTK_axialWidget,
                              vtkResliceImageView_Type::AXIAL);

    return;
}

void View_Dicom::slot_Coronal_FlipBtn_Horizontal_Clicked()
{
    this->flip_View(this->sp_Coronal_Viewer, imageFlip_Type::HORIZONTAL);
    this->fix_ViewScale_Width(this->sp_Coronal_Viewer,
                              this->ui->QVTK_coronalWidget,
                              vtkResliceImageView_Type::CORONAL);
    return;
}

void View_Dicom::slot_Coronal_FlipBtn_Vertical_Clicked()
{
    this->flip_View(this->sp_Coronal_Viewer, imageFlip_Type::VERTICAL);
    this->fix_ViewScale_Width(this->sp_Coronal_Viewer,
                              this->ui->QVTK_coronalWidget,
                              vtkResliceImageView_Type::CORONAL);
    return;
}

void View_Dicom::slot_Sagittal_FlipBtn_Horizontal_Clicked()
{
    this->flip_View(this->sp_Sagittal_Viewer, imageFlip_Type::HORIZONTAL);
    this->fix_ViewScale_Width(this->sp_Sagittal_Viewer,
                              this->ui->QVTK_sagittalWidget,
                              vtkResliceImageView_Type::SAGITTAL);
    return;
}

void View_Dicom::slot_Sagittal_FlipBtn_Vertical_Clicked()
{
    this->flip_View(this->sp_Sagittal_Viewer, imageFlip_Type::VERTICAL);
    this->fix_ViewScale_Width(this->sp_Sagittal_Viewer,
                              this->ui->QVTK_sagittalWidget,
                              vtkResliceImageView_Type::SAGITTAL);
    return;
}

void View_Dicom::slot_Coronal_RollBtn_Left_Clicked()
{
    this->roll_View(this->sp_Coronal_Viewer, imageRoll_Type::LEFT);

    this->fix_ViewScale_Width(this->sp_Coronal_Viewer,
                              this->ui->QVTK_coronalWidget,
                              vtkResliceImageView_Type::CORONAL);
    return;
}

void View_Dicom::slot_Coronal_RollBtn_Right_Clicked()
{
    this->roll_View(this->sp_Coronal_Viewer, imageRoll_Type::RIGHT);

    this->fix_ViewScale_Width(this->sp_Coronal_Viewer,
                              this->ui->QVTK_coronalWidget,
                              vtkResliceImageView_Type::CORONAL);

    return;
}

void View_Dicom::slot_Sagittal_RollBtn_Left_Clicked()
{
    this->roll_View(this->sp_Sagittal_Viewer, imageRoll_Type::LEFT);

    this->fix_ViewScale_Width(this->sp_Sagittal_Viewer,
                              this->ui->QVTK_sagittalWidget,
                              vtkResliceImageView_Type::SAGITTAL);
    return;
}

void View_Dicom::slot_Sagittal_RollBtn_Right_Clicked()
{
    this->roll_View(this->sp_Sagittal_Viewer, imageRoll_Type::RIGHT);

    this->fix_ViewScale_Width(this->sp_Sagittal_Viewer,
                              this->ui->QVTK_sagittalWidget,
                              vtkResliceImageView_Type::SAGITTAL);
    return;
}

void View_Dicom::slot_Axial_RollBtn_Left_Clicked()
{
    this->roll_View(this->sp_Axial_Viewer, imageRoll_Type::LEFT);

    this->fix_ViewScale_Width(this->sp_Axial_Viewer,
                              this->ui->QVTK_axialWidget,
                              vtkResliceImageView_Type::AXIAL);
    return;
}

void View_Dicom::slot_Axial_RollBtn_Right_Clicked()
{
    this->roll_View(this->sp_Axial_Viewer, imageRoll_Type::RIGHT);

    this->fix_ViewScale_Width(this->sp_Axial_Viewer,
                              this->ui->QVTK_axialWidget,
                              vtkResliceImageView_Type::AXIAL);

    return;
}

void View_Dicom::roll_View(vtkResliceImageViewer *p_Reslice_Viewer, const imageRoll_Type roll_Type)
{
    if (p_Reslice_Viewer == nullptr)
    {
        return;
    }

    p_Reslice_Viewer->GetRenderer()->ResetCamera();

    auto camera = p_Reslice_Viewer->GetRenderer()->GetActiveCamera();

    if (roll_Type == imageRoll_Type::LEFT)
    {
        camera->Roll(-90);
    }
    else if (roll_Type == imageRoll_Type::RIGHT)
    {
        camera->Roll(90);
    }
    return;
}

void View_Dicom::fix_ViewScale_Width(vtkResliceImageViewer *p_Reslice_Viewer,
                                     QVTKOpenGLNativeWidget *p_UI_Widget,
                                     const vtkResliceImageView_Type type)
{
    if (p_Reslice_Viewer == nullptr)
    {
        return;
    }

    // ResetCamera()는 이미지 전체가 보이게만 맞춤
    // 그러므로 여백이 생길 수 있음
    // 해당 여백을 가로 기준으로 확대하여 채움
    auto renderer = p_Reslice_Viewer->GetRenderer();
    auto camera = renderer->GetActiveCamera();
    auto imageActor = p_Reslice_Viewer->GetImageActor();

    int widgetWidth = p_UI_Widget->width();
    int widgetHeight = p_UI_Widget->height();

    if (widgetWidth <= 0 || widgetHeight <= 0)
    {
        qDebug() << "widgetWidth <= 0 || widgetHeight <= 0";
        return;
    }

    double aspect = static_cast<double>(widgetWidth) / static_cast<double>(widgetHeight);

    double bounds[6];
    imageActor->GetBounds(bounds);

    double imageWidth = 1.0;
    double imageHeight = 1.0;

    if (type == vtkResliceImageView_Type::AXIAL)
    {
        imageWidth = bounds[1] - bounds[0];  // X
        imageHeight = bounds[3] - bounds[2]; // Y
    }

    if (type == vtkResliceImageView_Type::CORONAL)
    {
        imageWidth = bounds[1] - bounds[0];  // X
        imageHeight = bounds[5] - bounds[4]; // Y
    }

    if (type == vtkResliceImageView_Type::SAGITTAL)
    {
        imageWidth = bounds[3] - bounds[2];  // X
        imageHeight = bounds[5] - bounds[4]; // Y
    }

    if (imageWidth <= 0.0 || imageHeight <= 0.0)
    {
        qDebug() << "imageWidth <= 0.0 || imageHeight <= 0.0";
        return;
    }

    renderer->ResetCamera();

    camera->ParallelProjectionOn();

    double scale = imageWidth / (2.0 * aspect);

    // 여백 scale값이 클수록 넓은 화면을 보는 것
    // 즉 실제 이미지는 작아보임
    if (type == vtkResliceImageView_Type::AXIAL)
    {
        scale = (scale * 1.2);
    }
    else if (type == vtkResliceImageView_Type::CORONAL || type == vtkResliceImageView_Type::SAGITTAL)
    {
        scale = (scale * 1.4);
    }

    camera->SetParallelScale(scale);

    renderer->ResetCameraClippingRange();
    p_Reslice_Viewer->Render();

    return;
}

void View_Dicom::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);

    QTimer::singleShot(5, [this]() { this->slot_MainWindow_Resize(); });
    return;
}

void View_Dicom::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    emit this->sig_MainWindow_Resize();
    return;
}

void View_Dicom::slot_MainWindow_Resize()
{
    int margin_Widget = 1;
    int x_axialBtn_Widget = this->ui->QVTK_axialWidget->width() - this->ui->axialBtn_Widget->width()
                            - margin_Widget;
    int y_axialBtn_Widget = margin_Widget;

    this->ui->axialBtn_Widget->move(x_axialBtn_Widget, y_axialBtn_Widget);

    int x_sagittalBtn_Widget = this->ui->QVTK_sagittalWidget->width()
                               - this->ui->sagittalBtn_Widget->width() - margin_Widget;
    int y_sagittalBtn_Widget = margin_Widget;

    this->ui->sagittalBtn_Widget->move(x_sagittalBtn_Widget, y_sagittalBtn_Widget);

    int x_coronalBtn_Widget = this->ui->QVTK_coronalWidget->width()
                              - this->ui->coronalBtn_Widget->width() - margin_Widget;
    int y_coronalBtn_Widget = margin_Widget;

    this->ui->coronalBtn_Widget->move(x_coronalBtn_Widget, y_coronalBtn_Widget);

    return;
}

void View_Dicom::init_UI_First()
{
    this->ui->horizontalLayout_5->setStretch(0, 2);
    this->ui->horizontalLayout_5->setStretch(1, 6);
    this->ui->horizontalLayout_5->setStretch(2, 6);
    this->ui->horizontalLayout_5->setStretch(3, 3);

    this->ui->axialBtn_Widget->raise();

    this->ui->verticalSlider->setEnabled(false);
    this->ui->verticalSlider_2->setEnabled(false);
    this->ui->verticalSlider_3->setEnabled(false);
    return;
}

void View_Dicom::set_ui_slider_vtkCommand(const vtkResliceImageView_Type type)
{
    if (type == vtkResliceImageView_Type::AXIAL)
    {
        QSignalBlocker blocker(this->ui->verticalSlider);
        int cur = this->sp_Axial_Viewer->GetSlice();
        this->ui->verticalSlider->setSliderPosition(cur);
    }
    else if (type == vtkResliceImageView_Type::SAGITTAL)
    {
        QSignalBlocker blocker(this->ui->verticalSlider_2);
        int cur = this->sp_Sagittal_Viewer->GetSlice();
        this->ui->verticalSlider_2->setSliderPosition(cur);
    }
    else if (type == vtkResliceImageView_Type::CORONAL)
    {
        QSignalBlocker blocker(this->ui->verticalSlider_3);
        int cur = this->sp_Coronal_Viewer->GetSlice();
        this->ui->verticalSlider_3->setSliderPosition(cur);
    }

    return;
}

void View_Dicom::init_Render_Windo()
{
    this->sp_Axial_Render_Windo = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

    ui->QVTK_axialWidget->setRenderWindow(this->sp_Axial_Render_Windo);

    this->sp_Coronal_Render_Windo = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

    ui->QVTK_coronalWidget->setRenderWindow(this->sp_Coronal_Render_Windo);

    this->sp_Sagittal_Render_Windo = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

    ui->QVTK_sagittalWidget->setRenderWindow(this->sp_Sagittal_Render_Windo);

    return;
}

void View_Dicom::init_connection()
{
    connect(this->ui->actionOpen_File,
            &QAction::triggered,
            this,
            &View_Dicom::slot_Action_FileOpen_Clicked);

    connect(this->ui->actionOpen_Directory,
            &QAction::triggered,
            this,
            &View_Dicom::slot_Action_DirectoryOpen_Clicked);

    connect(this->ui->verticalSlider, &QSlider::valueChanged, this, [this](int val) {
        this->sp_Axial_Viewer->SetSlice(val);
        this->sp_Axial_Viewer->Render();
        this->sp_Sagittal_Viewer->Render();
        this->sp_Coronal_Viewer->Render();
    });

    connect(this->ui->verticalSlider_2, &QSlider::valueChanged, this, [this](int val) {
        this->sp_Sagittal_Viewer->SetSlice(val);
        this->sp_Axial_Viewer->Render();
        this->sp_Sagittal_Viewer->Render();
        this->sp_Coronal_Viewer->Render();
    });

    connect(this->ui->verticalSlider_3, &QSlider::valueChanged, this, [this](int val) {
        this->sp_Coronal_Viewer->SetSlice(val);
        this->sp_Axial_Viewer->Render();
        this->sp_Sagittal_Viewer->Render();
        this->sp_Coronal_Viewer->Render();
    });

    connect(this, &View_Dicom::sig_MainWindow_Resize, this, &View_Dicom::slot_MainWindow_Resize);

    //===================== RollBtn =====================
    //===================== RollBtn =====================
    connect(this->ui->axial_Roll_Btn_Left,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Axial_RollBtn_Left_Clicked);

    connect(this->ui->axial_Roll_Btn_Right,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Axial_RollBtn_Right_Clicked);

    connect(this->ui->coronal_Roll_Btn_Left,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Coronal_RollBtn_Left_Clicked);

    connect(this->ui->coronal_Roll_Btn_Right,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Coronal_RollBtn_Right_Clicked);

    connect(this->ui->sagittal_Roll_Btn_Left,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Sagittal_RollBtn_Left_Clicked);

    connect(this->ui->sagittal_Roll_Btn_Right,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Sagittal_RollBtn_Right_Clicked);
    //===================== RollBtn =====================
    //===================== RollBtn =====================

    //===================== FlipBtn =====================
    //===================== FlipBtn =====================
    connect(this->ui->axial_Flip_Btn_Horizontal,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Axial_FlipBtn_Horizontal_Clicked);

    connect(this->ui->axial_Flip_Btn_Vertical,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Axial_FlipBtn_Vertical_Clicked);

    connect(this->ui->coronal_Flip_Btn_Horizontal,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Coronal_FlipBtn_Horizontal_Clicked);

    connect(this->ui->coronal_Flip_Btn_Vertical,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Coronal_FlipBtn_Vertical_Clicked);

    connect(this->ui->sagittal_Flip_Btn_Horizontal,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Sagittal_FlipBtn_Horizontal_Clicked);

    connect(this->ui->sagittal_Flip_Btn_Vertical,
            &QPushButton::clicked,
            this,
            &View_Dicom::slot_Sagittal_FlipBtn_Vertical_Clicked);
    //===================== FlipBtn =====================
    //===================== FlipBtn =====================
    return;
}

void View_Dicom::slot_Action_DirectoryOpen_Clicked()
{
    QString dir_Path = QFileDialog::getExistingDirectory(this, "testDir", QDir::currentPath());

    if (dir_Path.isEmpty())
    {
        return;
    }

    this->p_vm_Dicom->dicomFile_Load(dir_Path, path_Type::DIR_PATH);

    return;
}

void View_Dicom::slot_Action_FileOpen_Clicked()
{
    QString file_Path = QFileDialog::getOpenFileName(this, "hello test", QDir::currentPath());

    if (file_Path.isEmpty())
    {
        return;
    }

    this->p_vm_Dicom->dicomFile_Load(file_Path, path_Type::FILE_PATH);
    return;
}

void View_Dicom::slot_DicomFile_Reload_From_Store()
{
    int dims[3];
    this->p_vm_Dicom->get_store_image()->GetDimensions(dims);

    qDebug() << "DICOM dimensions:" << dims[0] << dims[1] << dims[2];

    if (this->sp_Axial_Viewer == nullptr)
    {
        this->init_Reslice_Viewr();
    }

    this->sp_Axial_Viewer->SetInputData(this->p_vm_Dicom->get_store_image());
    this->sp_Coronal_Viewer->SetInputData(this->p_vm_Dicom->get_store_image());
    this->sp_Sagittal_Viewer->SetInputData(this->p_vm_Dicom->get_store_image());

    // 슬라이스 중앙 설정
    int axial_slice_avgRange = (this->sp_Axial_Viewer->GetSliceMin()
                                + this->sp_Axial_Viewer->GetSliceMax())
                               / 2;

    int coronal_slice_avgRange = (this->sp_Coronal_Viewer->GetSliceMin()
                                  + this->sp_Coronal_Viewer->GetSliceMax())
                                 / 2;

    int sagittal_slice_avgRange = (this->sp_Sagittal_Viewer->GetSliceMin()
                                   + this->sp_Sagittal_Viewer->GetSliceMax())
                                  / 2;

    this->sp_Axial_Viewer->SetSlice(axial_slice_avgRange);
    this->sp_Coronal_Viewer->SetSlice(coronal_slice_avgRange);
    this->sp_Sagittal_Viewer->SetSlice(sagittal_slice_avgRange);

    // 밝기 / 대비 설정
    this->set_Color_Window_Level();

    /*
    this->sp_Axial_Viewer->GetRenderer()->ResetCamera();
    this->sp_Coronal_Viewer->GetRenderer()->ResetCamera();
    this->sp_Sagittal_Viewer->GetRenderer()->ResetCamera();

    this->sp_Axial_Viewer->GetRenderer()->ResetCameraClippingRange();
    this->sp_Coronal_Viewer->GetRenderer()->ResetCameraClippingRange();
    this->sp_Sagittal_Viewer->GetRenderer()->ResetCameraClippingRange();

    this->sp_Axial_Viewer->Render();
    this->sp_Coronal_Viewer->Render();
    this->sp_Sagittal_Viewer->Render();
    */

    this->fix_ViewScale_Width(this->sp_Axial_Viewer,
                              this->ui->QVTK_axialWidget,
                              vtkResliceImageView_Type::AXIAL);
    this->fix_ViewScale_Width(this->sp_Coronal_Viewer,
                              this->ui->QVTK_coronalWidget,
                              vtkResliceImageView_Type::CORONAL);
    this->fix_ViewScale_Width(this->sp_Sagittal_Viewer,
                              this->ui->QVTK_sagittalWidget,
                              vtkResliceImageView_Type::SAGITTAL);

    this->set_ui_slider();
    qDebug() << "Axial slice range:" << this->sp_Axial_Viewer->GetSliceMin()
             << this->sp_Axial_Viewer->GetSliceMax();

    qDebug() << "Coronal slice range:" << this->sp_Coronal_Viewer->GetSliceMin()
             << this->sp_Coronal_Viewer->GetSliceMax();

    qDebug() << "Sagittal slice range:" << this->sp_Sagittal_Viewer->GetSliceMin()
             << this->sp_Sagittal_Viewer->GetSliceMax();

    return;
}

void View_Dicom::set_ui_slider()
{
    // ===================== UI Slider =====================
    QSignalBlocker blk_1(this->ui->verticalSlider);
    QSignalBlocker blk_2(this->ui->verticalSlider_2);
    QSignalBlocker blk_3(this->ui->verticalSlider_3);

    this->ui->verticalSlider->setEnabled(true);
    this->ui->verticalSlider_2->setEnabled(true);
    this->ui->verticalSlider_3->setEnabled(true);

    this->ui->verticalSlider->setRange(this->sp_Axial_Viewer->GetSliceMin(),
                                       this->sp_Axial_Viewer->GetSliceMax());

    this->ui->verticalSlider_2->setRange(this->sp_Sagittal_Viewer->GetSliceMin(),
                                         this->sp_Sagittal_Viewer->GetSliceMax());

    this->ui->verticalSlider_3->setRange(this->sp_Coronal_Viewer->GetSliceMin(),
                                         this->sp_Coronal_Viewer->GetSliceMax());

    int axial_min = this->sp_Axial_Viewer->GetSliceMin();
    int axial_max = this->sp_Axial_Viewer->GetSliceMax();
    this->ui->verticalSlider->setSliderPosition((axial_min + axial_max) / 2);

    int sagittal_min = this->sp_Sagittal_Viewer->GetSliceMin();
    int sagittal_max = this->sp_Sagittal_Viewer->GetSliceMax();
    this->ui->verticalSlider_2->setSliderPosition((sagittal_min + sagittal_max) / 2);

    int coronal_min = this->sp_Coronal_Viewer->GetSliceMin();
    int coronal_max = this->sp_Coronal_Viewer->GetSliceMax();
    this->ui->verticalSlider_3->setSliderPosition((coronal_min + coronal_max) / 2);
    // ===================== UI Slider =====================
}

void View_Dicom::init_Reslice_Viewr()
{
    this->sp_Axial_Viewer = vtkSmartPointer<vtkResliceImageViewer>::New();
    this->sp_Coronal_Viewer = vtkSmartPointer<vtkResliceImageViewer>::New();
    this->sp_Sagittal_Viewer = vtkSmartPointer<vtkResliceImageViewer>::New();

    this->sp_Axial_Viewer->SetInputData(this->p_vm_Dicom->get_store_image());
    this->sp_Coronal_Viewer->SetInputData(this->p_vm_Dicom->get_store_image());
    this->sp_Sagittal_Viewer->SetInputData(this->p_vm_Dicom->get_store_image());

    this->sp_Axial_Viewer->SetRenderWindow(this->sp_Axial_Render_Windo);
    this->sp_Coronal_Viewer->SetRenderWindow(this->sp_Coronal_Render_Windo);
    this->sp_Sagittal_Viewer->SetRenderWindow(this->sp_Sagittal_Render_Windo);

    this->sp_Axial_Viewer->SetupInteractor(this->ui->QVTK_axialWidget->interactor());
    this->sp_Coronal_Viewer->SetupInteractor(this->ui->QVTK_coronalWidget->interactor());
    this->sp_Sagittal_Viewer->SetupInteractor(this->ui->QVTK_sagittalWidget->interactor());

    // reslice 모드
    this->sp_Axial_Viewer->SetResliceModeToAxisAligned();
    this->sp_Coronal_Viewer->SetResliceModeToAxisAligned();
    this->sp_Sagittal_Viewer->SetResliceModeToAxisAligned();

    this->sp_Axial_Viewer->SetSliceOrientationToXY();
    this->sp_Coronal_Viewer->SetSliceOrientationToXZ();
    this->sp_Sagittal_Viewer->SetSliceOrientationToYZ();

    // ===================== 슬라이더 Observer =====================
    // ===================== 슬라이더 Observer =====================
    this->sp_Axial_Viewer_Command = vtkSmartPointer<CallBack_VtkCommand>::New();
    this->sp_Axial_Viewer_Command->set_p_v_Dicom(this);
    this->sp_Axial_Viewer_Command->set_viewType(vtkResliceImageView_Type::AXIAL);
    this->sp_Axial_Viewer->AddObserver(vtkResliceImageViewer::SliceChangedEvent,
                                       this->sp_Axial_Viewer_Command);

    this->sp_Sagittal_Viewer_Command = vtkSmartPointer<CallBack_VtkCommand>::New();
    this->sp_Sagittal_Viewer_Command->set_p_v_Dicom(this);
    this->sp_Sagittal_Viewer_Command->set_viewType(vtkResliceImageView_Type::SAGITTAL);
    this->sp_Sagittal_Viewer->AddObserver(vtkResliceImageViewer::SliceChangedEvent,
                                          this->sp_Sagittal_Viewer_Command);

    this->sp_Coronal_Viewer_Command = vtkSmartPointer<CallBack_VtkCommand>::New();
    this->sp_Coronal_Viewer_Command->set_p_v_Dicom(this);
    this->sp_Coronal_Viewer_Command->set_viewType(vtkResliceImageView_Type::CORONAL);
    this->sp_Coronal_Viewer->AddObserver(vtkResliceImageViewer::SliceChangedEvent,
                                         this->sp_Coronal_Viewer_Command);
}

void View_Dicom::set_Color_Window_Level()
{
    double range[2];
    auto img = this->p_vm_Dicom->get_store_image();
    img->GetScalarRange(range);

    qDebug() << "Scalar range:" << range[0] << range[1];

    double mmin = range[0];
    double mmax = range[1];

    double window = mmax - mmin;
    double level = (mmax + mmin) / 3.0;

    // 대비 / 밝기
    this->sp_Axial_Viewer->SetColorWindow(window);
    this->sp_Axial_Viewer->SetColorLevel(level);
    this->sp_Coronal_Viewer->SetColorWindow(window);
    this->sp_Coronal_Viewer->SetColorLevel(level);
    this->sp_Sagittal_Viewer->SetColorWindow(window);
    this->sp_Sagittal_Viewer->SetColorLevel(level);

    return;
}
