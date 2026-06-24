#include "View_Dicom.h"
#include "./View/ui_View_Dicom.h"

View_Dicom::View_Dicom(VM_Dicom *vm_Dicom, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View_Dicom)
{
    ui->setupUi(this);
    this->ui->horizontalLayout_5->setStretch(0, 2);
    this->ui->horizontalLayout_5->setStretch(1, 5);
    this->ui->horizontalLayout_5->setStretch(2, 5);
    this->ui->horizontalLayout_5->setStretch(3, 3);
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

void View_Dicom::set_planeNomal(vtkSmartPointer<vtkResliceImageViewer> sp_Viewer, int planeNormal)
{
    qDebug() << Q_FUNC_INFO;

    auto widget = sp_Viewer->GetResliceCursorWidget();
    if (widget == nullptr)
    {
        qDebug() << "widget == nullptr";
        return;
    }

    auto rep = vtkResliceCursorLineRepresentation::SafeDownCast(widget->GetRepresentation());
    if (rep == nullptr)
    {
        qDebug() << "rep == nullptr";
        return;
    }

    auto actor = rep->GetResliceCursorActor();
    if (actor == nullptr)
    {
        qDebug() << "actor == nullptr";
        return;
    }

    auto algorithm = actor->GetCursorAlgorithm();
    if (algorithm == nullptr)
    {
        qDebug() << "algorithm  == nullptr";
        return;
    }

    algorithm->SetReslicePlaneNormal(planeNormal);
}

void View_Dicom::set_ui_slider_vtkCommand(const vtkResliceImageView_Type type)
{
    if (type == vtkResliceImageView_Type::AXIAL)
    {
        QSignalBlocker blocker(this->ui->verticalSlider);
        int cur = this->sp_Axial_Viewr->GetSlice();
        this->ui->verticalSlider->setSliderPosition(cur);
    }
    else if (type == vtkResliceImageView_Type::SAGITTAL)
    {
        QSignalBlocker blocker(this->ui->verticalSlider_2);
        int cur = this->sp_Sagittal_Viewr->GetSlice();
        this->ui->verticalSlider_2->setSliderPosition(cur);
    }
    else if (type == vtkResliceImageView_Type::CORONAL)
    {
        QSignalBlocker blocker(this->ui->verticalSlider_3);
        int cur = this->sp_Coronal_Viewr->GetSlice();
        this->ui->verticalSlider_3->setSliderPosition(cur);
    }

    return;
}

void View_Dicom::init_UI_First()
{
    this->ui->verticalSlider->setEnabled(false);
    this->ui->verticalSlider_2->setEnabled(false);
    this->ui->verticalSlider_3->setEnabled(false);
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
        this->sp_Axial_Viewr->SetSlice(val);
        this->sp_Axial_Viewr->Render();
        this->sp_Sagittal_Viewr->Render();
        this->sp_Coronal_Viewr->Render();
    });

    connect(this->ui->verticalSlider_2, &QSlider::valueChanged, this, [this](int val) {
        this->sp_Sagittal_Viewr->SetSlice(val);
        this->sp_Axial_Viewr->Render();
        this->sp_Sagittal_Viewr->Render();
        this->sp_Coronal_Viewr->Render();
    });

    connect(this->ui->verticalSlider_3, &QSlider::valueChanged, this, [this](int val) {
        this->sp_Coronal_Viewr->SetSlice(val);
        this->sp_Axial_Viewr->Render();
        this->sp_Sagittal_Viewr->Render();
        this->sp_Coronal_Viewr->Render();
    });

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

    if (this->sp_Axial_Viewr == nullptr)
    {
        this->init_Reslice_Viewr();
    }

    this->sp_Axial_Viewr->SetInputData(this->p_vm_Dicom->get_store_image());
    this->sp_Coronal_Viewr->SetInputData(this->p_vm_Dicom->get_store_image());
    this->sp_Sagittal_Viewr->SetInputData(this->p_vm_Dicom->get_store_image());

    // reslice 모드
    this->sp_Axial_Viewr->SetResliceModeToAxisAligned();
    this->sp_Coronal_Viewr->SetResliceModeToAxisAligned();
    this->sp_Sagittal_Viewr->SetResliceModeToAxisAligned();

    this->sp_Axial_Viewr->SetSliceOrientationToXY();
    this->sp_Coronal_Viewr->SetSliceOrientationToXZ();
    this->sp_Sagittal_Viewr->SetSliceOrientationToYZ();

    // 십자선 공유
    vtkResliceCursor *sharedCursor = this->sp_Axial_Viewr->GetResliceCursor();

    sharedCursor->SetImage(this->p_vm_Dicom->get_store_image());

    this->sp_Coronal_Viewr->SetResliceCursor(sharedCursor);
    this->sp_Sagittal_Viewr->SetResliceCursor(sharedCursor);

    // 화면 재 보정
    this->sp_Axial_Viewr->SetSliceOrientationToXY();
    this->sp_Coronal_Viewr->SetSliceOrientationToXZ();
    this->sp_Sagittal_Viewr->SetSliceOrientationToYZ();

    // 삽자선 중심
    double center[3];
    this->p_vm_Dicom->get_store_image()->GetCenter(center);
    sharedCursor->SetCenter(center);

    // plane normal 설정
    this->set_planeNomal(this->sp_Axial_Viewr, 2);
    this->set_planeNomal(this->sp_Coronal_Viewr, 1);
    this->set_planeNomal(this->sp_Sagittal_Viewr, 0);

    // renderer 설정
    this->sp_Axial_Viewr->GetResliceCursorWidget()->SetDefaultRenderer(
        this->sp_Axial_Viewr->GetRenderer());
    this->sp_Coronal_Viewr->GetResliceCursorWidget()->SetDefaultRenderer(
        this->sp_Coronal_Viewr->GetRenderer());
    this->sp_Sagittal_Viewr->GetResliceCursorWidget()->SetDefaultRenderer(
        this->sp_Sagittal_Viewr->GetRenderer());

    // 십자선 활성화
    this->sp_Axial_Viewr->GetResliceCursorWidget()->EnabledOn();
    this->sp_Coronal_Viewr->GetResliceCursorWidget()->EnabledOn();
    this->sp_Sagittal_Viewr->GetResliceCursorWidget()->EnabledOn();

    // 슬라이스 중앙 설정
    int axial_slice_avgRange = (this->sp_Axial_Viewr->GetSliceMin()
                                + this->sp_Axial_Viewr->GetSliceMax())
                               / 2;

    int coronal_slice_avgRange = (this->sp_Coronal_Viewr->GetSliceMin()
                                  + this->sp_Coronal_Viewr->GetSliceMax())
                                 / 2;

    int sagittal_slice_avgRange = (this->sp_Sagittal_Viewr->GetSliceMin()
                                   + this->sp_Sagittal_Viewr->GetSliceMax())
                                  / 2;

    this->sp_Axial_Viewr->SetSlice(axial_slice_avgRange);
    this->sp_Coronal_Viewr->SetSlice(coronal_slice_avgRange);
    this->sp_Sagittal_Viewr->SetSlice(sagittal_slice_avgRange);

    // 밝기 / 대비 설정
    this->set_Color_Window_Level();

    this->sp_Axial_Viewr->GetRenderer()->ResetCamera();
    this->sp_Coronal_Viewr->GetRenderer()->ResetCamera();
    this->sp_Sagittal_Viewr->GetRenderer()->ResetCamera();

    this->sp_Axial_Viewr->GetRenderer()->ResetCameraClippingRange();
    this->sp_Coronal_Viewr->GetRenderer()->ResetCameraClippingRange();
    this->sp_Sagittal_Viewr->GetRenderer()->ResetCameraClippingRange();

    this->set_ui_slider();

    this->sp_Axial_Viewr->Render();
    this->sp_Coronal_Viewr->Render();
    this->sp_Sagittal_Viewr->Render();

    qDebug() << "Axial slice range:" << this->sp_Axial_Viewr->GetSliceMin()
             << this->sp_Axial_Viewr->GetSliceMax();

    qDebug() << "Coronal slice range:" << this->sp_Coronal_Viewr->GetSliceMin()
             << this->sp_Coronal_Viewr->GetSliceMax();

    qDebug() << "Sagittal slice range:" << this->sp_Sagittal_Viewr->GetSliceMin()
             << this->sp_Sagittal_Viewr->GetSliceMax();

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

    this->ui->verticalSlider->setRange(this->sp_Axial_Viewr->GetSliceMin(),
                                       this->sp_Axial_Viewr->GetSliceMax());

    this->ui->verticalSlider_2->setRange(this->sp_Sagittal_Viewr->GetSliceMin(),
                                         this->sp_Sagittal_Viewr->GetSliceMax());

    this->ui->verticalSlider_3->setRange(this->sp_Coronal_Viewr->GetSliceMin(),
                                         this->sp_Coronal_Viewr->GetSliceMax());

    int axial_min = this->sp_Axial_Viewr->GetSliceMin();
    int axial_max = this->sp_Axial_Viewr->GetSliceMax();
    this->ui->verticalSlider->setSliderPosition((axial_min + axial_max) / 2);

    int sagittal_min = this->sp_Sagittal_Viewr->GetSliceMin();
    int sagittal_max = this->sp_Sagittal_Viewr->GetSliceMax();
    this->ui->verticalSlider_2->setSliderPosition((sagittal_min + sagittal_max) / 2);

    int coronal_min = this->sp_Coronal_Viewr->GetSliceMin();
    int coronal_max = this->sp_Coronal_Viewr->GetSliceMax();
    this->ui->verticalSlider_3->setSliderPosition((coronal_min + coronal_max) / 2);
    // ===================== UI Slider =====================
}

void View_Dicom::init_Reslice_Viewr()
{
    //
    this->sp_Axial_Viewr = vtkSmartPointer<vtkResliceImageViewer>::New();
    this->sp_Coronal_Viewr = vtkSmartPointer<vtkResliceImageViewer>::New();
    this->sp_Sagittal_Viewr = vtkSmartPointer<vtkResliceImageViewer>::New();

    this->sp_Axial_Viewr->SetInputData(this->p_vm_Dicom->get_store_image());
    this->sp_Coronal_Viewr->SetInputData(this->p_vm_Dicom->get_store_image());
    this->sp_Sagittal_Viewr->SetInputData(this->p_vm_Dicom->get_store_image());

    this->sp_Axial_Viewr->SetRenderWindow(this->sp_Axial_Render_Windo);
    this->sp_Coronal_Viewr->SetRenderWindow(this->sp_Coronal_Render_Windo);
    this->sp_Sagittal_Viewr->SetRenderWindow(this->sp_Sagittal_Render_Windo);

    this->sp_Axial_Viewr->SetupInteractor(this->ui->QVTK_axialWidget->interactor());
    this->sp_Coronal_Viewr->SetupInteractor(this->ui->QVTK_coronalWidget->interactor());
    this->sp_Sagittal_Viewr->SetupInteractor(this->ui->QVTK_sagittalWidget->interactor());

    // reslice 모드
    this->sp_Axial_Viewr->SetResliceModeToAxisAligned();
    this->sp_Coronal_Viewr->SetResliceModeToAxisAligned();
    this->sp_Sagittal_Viewr->SetResliceModeToAxisAligned();

    this->sp_Axial_Viewr->SetSliceOrientationToXY();
    this->sp_Coronal_Viewr->SetSliceOrientationToXZ();
    this->sp_Sagittal_Viewr->SetSliceOrientationToYZ();

    // ===================== 슬라이더 Observer =====================
    // ===================== 슬라이더 Observer =====================
    this->sp_Axial_Viewer_Command = vtkSmartPointer<CallBack_VtkCommand>::New();
    this->sp_Axial_Viewer_Command->set_p_v_Dicom(this);
    this->sp_Axial_Viewer_Command->set_viewType(vtkResliceImageView_Type::AXIAL);
    this->sp_Axial_Viewr->AddObserver(vtkResliceImageViewer::SliceChangedEvent,
                                      this->sp_Axial_Viewer_Command);

    this->sp_Sagittal_Viewer_Command = vtkSmartPointer<CallBack_VtkCommand>::New();
    this->sp_Sagittal_Viewer_Command->set_p_v_Dicom(this);
    this->sp_Sagittal_Viewer_Command->set_viewType(vtkResliceImageView_Type::SAGITTAL);
    this->sp_Sagittal_Viewr->AddObserver(vtkResliceImageViewer::SliceChangedEvent,
                                         this->sp_Sagittal_Viewer_Command);

    this->sp_Coronal_Viewer_Command = vtkSmartPointer<CallBack_VtkCommand>::New();
    this->sp_Coronal_Viewer_Command->set_p_v_Dicom(this);
    this->sp_Coronal_Viewer_Command->set_viewType(vtkResliceImageView_Type::CORONAL);
    this->sp_Coronal_Viewr->AddObserver(vtkResliceImageViewer::SliceChangedEvent,
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
    this->sp_Axial_Viewr->SetColorWindow(window);
    this->sp_Axial_Viewr->SetColorLevel(level);
    this->sp_Coronal_Viewr->SetColorWindow(window);
    this->sp_Coronal_Viewr->SetColorLevel(level);
    this->sp_Sagittal_Viewr->SetColorWindow(window);
    this->sp_Sagittal_Viewr->SetColorLevel(level);

    return;
}
