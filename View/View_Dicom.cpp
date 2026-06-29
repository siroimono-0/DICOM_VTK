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

void View_Dicom::tableWidget_Setting_In_slot_TreeItem_Clicked(const QTreeWidgetItem *item,
                                                              const int col)
{
    // ================= TableWidget 세팅 =================
    // ================= TableWidget 세팅 =================
    // Patient
    QTableWidgetItem *patientName = new QTableWidgetItem();
    QString s1 = item->data(col, Role_patientName).toString();
    patientName->setText(s1);
    this->ui->tableWidget->setItem(0, 1, patientName);

    QTableWidgetItem *patientID = new QTableWidgetItem();
    QString s2 = item->data(col, Role_patientID).toString();
    patientID->setText(s2);
    this->ui->tableWidget->setItem(1, 1, patientID);

    QTableWidgetItem *patientBirthDate = new QTableWidgetItem();
    QString s3 = item->data(col, Role_patientBirthDate).toString();
    patientBirthDate->setText(s3);
    this->ui->tableWidget->setItem(2, 1, patientBirthDate);

    QTableWidgetItem *patientSex = new QTableWidgetItem();
    QString s4 = item->data(col, Role_patientSex).toString();
    patientSex->setText(s4);
    this->ui->tableWidget->setItem(3, 1, patientSex);

    QTableWidgetItem *patientAge = new QTableWidgetItem();
    QString s5 = item->data(col, Role_patientAge).toString();
    patientAge->setText(s5);
    this->ui->tableWidget->setItem(4, 1, patientAge);

    QTableWidgetItem *patientWeight = new QTableWidgetItem();
    QString s6 = item->data(col, Role_patientWeight).toString();
    patientWeight->setText(s6);
    this->ui->tableWidget->setItem(5, 1, patientWeight);

    QTableWidgetItem *patientAddress = new QTableWidgetItem();
    QString s7 = item->data(col, Role_patientAddress).toString();
    patientAddress->setText(s7);
    this->ui->tableWidget->setItem(6, 1, patientAddress);

    // Study
    QTableWidgetItem *studyDate = new QTableWidgetItem();
    QString s8 = item->data(col, Role_studyDate).toString();
    studyDate->setText(s8);
    this->ui->tableWidget->setItem(8, 1, studyDate);

    QTableWidgetItem *studyTime = new QTableWidgetItem();
    QString s9 = item->data(col, Role_studyTime).toString();
    studyTime->setText(s9);
    this->ui->tableWidget->setItem(9, 1, studyTime);

    QTableWidgetItem *studyID = new QTableWidgetItem();
    QString s10 = item->data(col, Role_studyID).toString();
    studyID->setText(s10);
    this->ui->tableWidget->setItem(10, 1, studyID);

    // Modality
    QTableWidgetItem *modality = new QTableWidgetItem();
    QString s11 = item->data(col, Role_modality).toString();
    modality->setText(s11);
    this->ui->tableWidget->setItem(11, 1, modality);

    QTableWidgetItem *studyDescription = new QTableWidgetItem();
    QString s12 = item->data(col, Role_studyDescription).toString();
    studyDescription->setText(s12);
    this->ui->tableWidget->setItem(12, 1, studyDescription);

    // Series
    QTableWidgetItem *seriesDate = new QTableWidgetItem();
    QString s13 = item->data(col, Role_seriesDate).toString();
    seriesDate->setText(s13);
    this->ui->tableWidget->setItem(14, 1, seriesDate);

    QTableWidgetItem *seriesTime = new QTableWidgetItem();
    QString s14 = item->data(col, Role_seriesTime).toString();
    seriesTime->setText(s14);
    this->ui->tableWidget->setItem(15, 1, seriesTime);

    QTableWidgetItem *seriesDescription = new QTableWidgetItem();
    QString s15 = item->data(col, Role_seriesDescription).toString();
    seriesDescription->setText(s15);
    this->ui->tableWidget->setItem(16, 1, seriesDescription);
    // ================= TableWidget 세팅 =================
    // ================= TableWidget 세팅 =================

    return;
}

void View_Dicom::label_Setting_In_slot_TreeItem_Clicked(const QTreeWidgetItem *item, const int col)
{
    // ===================== 왼쪽 위 =====================
    // ===================== 왼쪽 위 =====================
    QString patientName = item->data(col, Role_patientName).toString();
    this->ui->axialLabel_Patient_Name->setText(patientName);

    QString patientID = item->data(col, Role_patientID).toString();
    this->ui->axialLabel_Patient_ID->setText(patientID);

    QString patientBirthDate = item->data(col, Role_patientBirthDate).toString();
    this->ui->axialLabel_Patient_Birth_Date->setText(patientBirthDate);

    QString studyDescription = item->data(col, Role_studyDescription).toString();
    this->ui->axialLabel_Study_Description->setText(studyDescription);

    QString seriesDescription = item->data(col, Role_seriesDescription).toString();
    this->ui->axialLabel_Series_Description->setText(seriesDescription);
    // ===================== 왼쪽 위 =====================
    // ===================== 왼쪽 위 =====================

    // ===================== 오른쪽 위 =====================
    // ===================== 오른쪽 위 =====================
    QString institutionName = item->data(col, Role_institutionName).toString();
    this->ui->axialLabel_Institution_Name->setText(institutionName);

    QString manufacturerModelName = item->data(col, Role_manufacturerModelName).toString();
    this->ui->axialLabel_Manufacturer_Model_Name->setText(manufacturerModelName);

    QString acquisitionDate = item->data(col, Role_acquisitionDate).toString();
    this->ui->axialLabel_Acquisition_Date->setText(acquisitionDate);

    QString acquisitionTime = item->data(col, Role_acquisitionTime).toString();
    this->ui->axialLabel_Acquisition_Time->setText(acquisitionTime);
    // ===================== 오른쪽 위 =====================
    // ===================== 오른쪽 위 =====================

    // ===================== 왼쪽 아래 =====================
    // ===================== 왼쪽 아래 =====================
    QString sliceThickness = item->data(col, Role_sliceThickness).toString();
    this->ui->axialLabel_Slice_Thickness->setText(sliceThickness);

    QString sliceLocation = item->data(col, Role_sliceLocation).toString();
    this->ui->axialLabel_Slice_Location->setText(sliceLocation);

    QString modality = item->data(col, Role_modality).toString();
    this->ui->axialLabel_Modality->setText(modality);

    QString instanceNumber = item->data(col, Role_instanceNumber).toString();
    this->ui->axialLabel_Instance_Number->setText(instanceNumber);

    QString seriesNumber = item->data(col, Role_seriesNumber).toString();
    this->ui->axialLabel_Series_Number->setText(seriesNumber);
    // ===================== 왼쪽 아래 =====================
    // ===================== 왼쪽 아래 =====================

    return;
}

void View_Dicom::slot_TreeItem_Clicked(QTreeWidgetItem *item, int col)
{
    QString selectUID = item->data(col, Role_seriesInstanceUID).toString();
    QString tmp = this->p_vm_Dicom->get_Store_seriesInstanceUID();
    if (selectUID != tmp)
    {
        // 이미지 변경
        this->p_vm_Dicom->set_Store_ImageData_UID(selectUID);
        this->p_vm_Dicom->set_Store_seriesInstanceUID(selectUID);
    }

    int number = this->cnv_Slice_To_Row(item->data(col, Role_Number).toInt());
    this->ui->verticalSlider->setValue(number);

    this->tableWidget_Setting_In_slot_TreeItem_Clicked(item, col);
    this->label_Setting_In_slot_TreeItem_Clicked(item, col);
}

void View_Dicom::slot_create_Mp_DicomMetaDat_From_Store()
{
    this->ui->treeWidget->setSortingEnabled(false);
    this->ui->treeWidget->clear();

    this->mp_DicomMetaData = this->p_vm_Dicom->get_Store_DicomMetaMap();

    for (auto it = this->mp_DicomMetaData.begin(); it != this->mp_DicomMetaData.end(); it++)
    {
        // delete 자원회수는 QTreeWidget이 갖어감
        QTreeWidgetItem *seriesItem = new QTreeWidgetItem();
        seriesItem->setText(0, it.key());
        this->ui->treeWidget->addTopLevelItem(seriesItem);

        for (const dicomMetaData &metaData : it.value())
        {
            QTreeWidgetItem *metaItem = new QTreeWidgetItem();
            metaItem->setText(0, metaData.fileName);
            metaItem->setData(0, Role_Number, metaData.SliceIndex);
            metaItem->setData(0, Role_patientName, metaData.patientName);
            metaItem->setData(0, Role_patientID, metaData.patientID);
            metaItem->setData(0, Role_patientBirthDate, metaData.patientBirthDate);
            metaItem->setData(0, Role_patientSex, metaData.patientSex);
            metaItem->setData(0, Role_patientAge, metaData.patientAge);
            metaItem->setData(0, Role_patientWeight, metaData.patientWeight);
            metaItem->setData(0, Role_patientAddress, metaData.patientAddress);
            metaItem->setData(0, Role_studyDate, metaData.studyDate);
            metaItem->setData(0, Role_studyTime, metaData.studyTime);
            metaItem->setData(0, Role_studyID, metaData.studyID);
            metaItem->setData(0, Role_modality, metaData.modality);
            metaItem->setData(0, Role_studyDescription, metaData.studyDescription);
            metaItem->setData(0, Role_seriesDate, metaData.seriesDate);
            metaItem->setData(0, Role_seriesTime, metaData.seriesTime);
            metaItem->setData(0, Role_seriesDescription, metaData.seriesDescription);
            metaItem->setData(0, Role_seriesInstanceUID, metaData.seriesInstanceUID);

            metaItem->setData(0, Role_seriesDescription, metaData.seriesDescription);
            metaItem->setData(0, Role_institutionName, metaData.institutionName);
            metaItem->setData(0, Role_manufacturerModelName, metaData.manufacturerModelName);
            metaItem->setData(0, Role_acquisitionDate, metaData.acquisitionDate);
            metaItem->setData(0, Role_acquisitionTime, metaData.acquisitionTime);
            metaItem->setData(0, Role_sliceThickness, metaData.sliceThickness);
            metaItem->setData(0, Role_sliceLocation, metaData.sliceLocation);
            metaItem->setData(0, Role_seriesNumber, metaData.seriesNumber);
            metaItem->setData(0, Role_instanceNumber, metaData.instanceNumber);

            seriesItem->addChild(metaItem);
            // seriesItem->insertChild(0, metaItem);
        }
    }

    return;
}

void View_Dicom::set_UI_YX_vtkCommand(const int pos_Y,
                                      const int pos_X,
                                      const vtkResliceImageView_Type type)
{
    if (type == vtkResliceImageView_Type::AXIAL)
    {
        QString s = QString("X : %1mm   Y : %2mm").arg(pos_X).arg(pos_Y);
        this->ui->axial_XY_Label->setText(s);
    }
    else if (type == vtkResliceImageView_Type::SAGITTAL)
    {
        QString s = QString("X : %1mm   Y : %2mm").arg(pos_X).arg(pos_Y);
        this->ui->sagittal_XY_Label->setText(s);
    }
    else if (type == vtkResliceImageView_Type::CORONAL)
    {
        QString s = QString("X : %1mm   Y : %2mm").arg(pos_X).arg(pos_Y);
        this->ui->coronal_XY_Label->setText(s);
    }
    return;
}

void View_Dicom::update_CrossHairLines()
{
    auto image = this->p_vm_Dicom->get_store_image();

    if (image == nullptr)
    {
        return;
    }

    double bound[6];
    double origin[3];
    double spacing[3];

    image->GetBounds(bound);
    image->GetOrigin(origin);
    image->GetSpacing(spacing);

    double x = origin[0] + this->cursorIndex[0] * spacing[0];
    double y = origin[1] + this->cursorIndex[1] * spacing[1];
    double z = origin[2] + this->cursorIndex[2] * spacing[2];

    // Axial XY plane, z고정 ?
    this->st_Axial_Cross.line_1->SetPoint1(bound[0], y, z);
    this->st_Axial_Cross.line_1->SetPoint2(bound[1], y, z);

    this->st_Axial_Cross.line_2->SetPoint1(x, bound[2], z);
    this->st_Axial_Cross.line_2->SetPoint2(x, bound[3], z);

    // Sagittal YZ. x
    this->st_Sagittal_Cross.line_1->SetPoint1(x, bound[2], z);
    this->st_Sagittal_Cross.line_1->SetPoint2(x, bound[3], z);

    this->st_Sagittal_Cross.line_2->SetPoint1(x, y, bound[4]);
    this->st_Sagittal_Cross.line_2->SetPoint2(x, y, bound[5]);

    // Sagittal XZ. y
    this->st_Coronal_Cross.line_1->SetPoint1(bound[0], y, z);
    this->st_Coronal_Cross.line_1->SetPoint2(bound[1], y, z);

    this->st_Coronal_Cross.line_2->SetPoint1(x, y, bound[4]);
    this->st_Coronal_Cross.line_2->SetPoint2(x, y, bound[5]);

    this->st_Axial_Cross.line_1->Modified();
    this->st_Axial_Cross.line_2->Modified();
    this->st_Coronal_Cross.line_1->Modified();
    this->st_Coronal_Cross.line_2->Modified();
    this->st_Sagittal_Cross.line_1->Modified();
    this->st_Sagittal_Cross.line_2->Modified();
    return;
}

void View_Dicom::init_CrossHairLines(crossHairLines &cross,
                                     vtkRenderer *render,
                                     const crossHairLines_Type type)
{
    cross.line_1 = vtkSmartPointer<vtkLineSource>::New();
    cross.line_2 = vtkSmartPointer<vtkLineSource>::New();

    cross.mapper_1 = vtkSmartPointer<vtkPolyDataMapper>::New();
    cross.mapper_2 = vtkSmartPointer<vtkPolyDataMapper>::New();

    cross.mapper_1->SetInputConnection(cross.line_1->GetOutputPort());
    cross.mapper_2->SetInputConnection(cross.line_2->GetOutputPort());

    cross.actor_1 = vtkSmartPointer<vtkActor>::New();
    cross.actor_2 = vtkSmartPointer<vtkActor>::New();

    cross.actor_1->SetMapper(cross.mapper_1);
    cross.actor_2->SetMapper(cross.mapper_2);

    if (type == crossHairLines_Type::AXIAL)
    {
        cross.actor_1->GetProperty()->SetColor(1.0, 0.0, 0.0); // red
        cross.actor_2->GetProperty()->SetColor(0.0, 1.0, 0.0); // green
    }
    else if (type == crossHairLines_Type::CORONAL)
    {
        cross.actor_1->GetProperty()->SetColor(0.0, 0.0, 1.0); // blue
        cross.actor_2->GetProperty()->SetColor(0.0, 1.0, 0.0); // green
    }
    else if (type == crossHairLines_Type::SAGITTAL)
    {
        cross.actor_1->GetProperty()->SetColor(0.0, 0.0, 1.0); // blue
        cross.actor_2->GetProperty()->SetColor(1.0, 0.0, 0.0); // red
    }

    cross.actor_1->GetProperty()->SetLineWidth(1.0);
    cross.actor_2->GetProperty()->SetLineWidth(1.0);

    render->AddActor(cross.actor_1);
    render->AddActor(cross.actor_2);
    return;
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
    //===================== 버튼 위젯 배치 =====================
    //===================== 버튼 위젯 배치 =====================
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
    //===================== 버튼 위젯 배치 =====================
    //===================== 버튼 위젯 배치 =====================

    //===================== XY 라벨 배치 =====================
    //===================== XY 라벨 배치 =====================
    int x_axial_XY_Label = this->ui->QVTK_axialWidget->width() - 230;
    int y_axial_XY_Label = this->ui->QVTK_axialWidget->height() - 100;
    this->ui->axial_XY_Label->move(x_axial_XY_Label, y_axial_XY_Label);

    int x_sagittal_XY_Label = this->ui->QVTK_sagittalWidget->width() - 230;
    int y_sagittal_XY_Label = this->ui->QVTK_sagittalWidget->height() - 50;
    this->ui->sagittal_XY_Label->move(x_sagittal_XY_Label, y_sagittal_XY_Label);

    int x_coronal_XY_Label = this->ui->QVTK_coronalWidget->width() - 230;
    int y_coronal_XY_Label = this->ui->QVTK_coronalWidget->height() - 50;
    this->ui->coronal_XY_Label->move(x_coronal_XY_Label, y_coronal_XY_Label);
    //===================== XY 라벨 배치 =====================
    //===================== XY 라벨 배치 =====================

    return;
}

int View_Dicom::cnv_Slice_To_Row(int slice)
{
    int sliceMax = this->sp_Axial_Viewer->GetSliceMax();
    return sliceMax - slice;
}

int View_Dicom::cnv_Row_To_Slice(int row)
{
    int sliceMax = this->sp_Axial_Viewer->GetSliceMax();
    return sliceMax - row;
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

    this->ui->tableWidget->verticalHeader()->hide();
    this->ui->tableWidget->setHorizontalHeaderLabels({"Tag Description", "Value"});
    QFont headerFont;
    headerFont.setPointSize(12);
    headerFont.setBold(true);
    this->ui->tableWidget->horizontalHeader()->setFont(headerFont);
    // this->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->ui->tableWidget->setColumnWidth(0, 150);
    this->ui->tableWidget->setColumnWidth(1, 200);

    QFont sellFont;
    sellFont.setPointSize(12);
    this->ui->tableWidget->setFont(sellFont);
    this->ui->tableWidget->setRowHeight(0, 40);
    this->ui->tableWidget->setRowHeight(1, 40);
    this->ui->tableWidget->setRowHeight(2, 40);
    this->ui->tableWidget->setRowHeight(3, 40);
    this->ui->tableWidget->setRowHeight(4, 40);
    this->ui->tableWidget->setRowHeight(5, 40);
    this->ui->tableWidget->setRowHeight(6, 40);
    this->ui->tableWidget->setRowHeight(7, 40);
    this->ui->tableWidget->setRowHeight(8, 40);
    this->ui->tableWidget->setRowHeight(9, 40);
    this->ui->tableWidget->setRowHeight(10, 40);
    this->ui->tableWidget->setRowHeight(11, 40);
    this->ui->tableWidget->setRowHeight(12, 40);
    this->ui->tableWidget->setRowHeight(13, 40);
    this->ui->tableWidget->setRowHeight(14, 40);
    this->ui->tableWidget->setRowHeight(15, 40);
    this->ui->tableWidget->setRowHeight(16, 40);

    ui->verticalSlider->setInvertedAppearance(true);
    ui->verticalSlider_2->setInvertedAppearance(true);
    ui->verticalSlider_3->setInvertedAppearance(true);

    // ui->verticalSlider->setInvertedControls(false);
    // ui->verticalSlider_2->setInvertedControls(false);
    // ui->verticalSlider_3->setInvertedControls(false);
    return;
}
/*
(0008,0005)

 */

QTreeWidgetItem *View_Dicom::find_TopLevleItem(const QString uid)
{
    for (int i = 0; i < this->ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem *item = this->ui->treeWidget->topLevelItem(i);

        QString tmp = item->text(0);
        if (tmp == uid)
        {
            return item;
        }
    }
    return nullptr;
}

void View_Dicom::set_UI_slider_vtkCommand(const vtkResliceImageView_Type type)
{
    if (type == vtkResliceImageView_Type::AXIAL)
    {
        QSignalBlocker blocker(this->ui->verticalSlider);
        int tmp = this->sp_Axial_Viewer->GetSlice();
        int cur = this->cnv_Slice_To_Row(tmp);
        this->ui->verticalSlider->setSliderPosition(cur);

        auto parent_Item = this->find_TopLevleItem(this->p_vm_Dicom->get_Store_seriesInstanceUID());
        auto child_Item = parent_Item->child(cur);
        if (child_Item != nullptr)
        {
            parent_Item->setExpanded(true);
            this->ui->treeWidget->setCurrentItem(child_Item);
            this->ui->treeWidget->scrollToItem(child_Item);
            this->slot_TreeItem_Clicked(child_Item, 0);
        }

        this->cursorIndex[2] = tmp;
        this->sp_Axial_Viewer->SetSlice(cursorIndex[2]);
        this->sp_Sagittal_Viewer->SetSlice(cursorIndex[0]);
        this->sp_Coronal_Viewer->SetSlice(cursorIndex[1]);

        this->update_CrossHairLines();

        this->sp_Axial_Viewer->Render();
        this->sp_Sagittal_Viewer->Render();
        this->sp_Coronal_Viewer->Render();
    }
    else if (type == vtkResliceImageView_Type::SAGITTAL)
    {
        QSignalBlocker blocker(this->ui->verticalSlider_2);
        int cur = this->sp_Sagittal_Viewer->GetSlice();
        this->ui->verticalSlider_2->setSliderPosition(cur);

        this->cursorIndex[0] = cur;
        this->sp_Axial_Viewer->SetSlice(cursorIndex[2]);
        this->sp_Sagittal_Viewer->SetSlice(cursorIndex[0]);
        this->sp_Coronal_Viewer->SetSlice(cursorIndex[1]);

        this->update_CrossHairLines();

        this->sp_Axial_Viewer->Render();
        this->sp_Sagittal_Viewer->Render();
        this->sp_Coronal_Viewer->Render();
    }
    else if (type == vtkResliceImageView_Type::CORONAL)
    {
        QSignalBlocker blocker(this->ui->verticalSlider_3);
        int cur = this->sp_Coronal_Viewer->GetSlice();
        this->ui->verticalSlider_3->setSliderPosition(cur);

        this->cursorIndex[1] = cur;
        this->sp_Axial_Viewer->SetSlice(cursorIndex[2]);
        this->sp_Sagittal_Viewer->SetSlice(cursorIndex[0]);
        this->sp_Coronal_Viewer->SetSlice(cursorIndex[1]);

        this->update_CrossHairLines();

        this->sp_Axial_Viewer->Render();
        this->sp_Sagittal_Viewer->Render();
        this->sp_Coronal_Viewer->Render();
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
        int slice = this->cnv_Slice_To_Row(val);

        this->cursorIndex[2] = slice;
        this->sp_Axial_Viewer->SetSlice(cursorIndex[2]);
        this->sp_Sagittal_Viewer->SetSlice(cursorIndex[0]);
        this->sp_Coronal_Viewer->SetSlice(cursorIndex[1]);

        this->update_CrossHairLines();

        this->sp_Axial_Viewer->Render();
        this->sp_Sagittal_Viewer->Render();
        this->sp_Coronal_Viewer->Render();
    });

    connect(this->ui->verticalSlider_2, &QSlider::valueChanged, this, [this](int val) {
        this->cursorIndex[0] = val;
        this->sp_Axial_Viewer->SetSlice(cursorIndex[2]);
        this->sp_Sagittal_Viewer->SetSlice(cursorIndex[0]);
        this->sp_Coronal_Viewer->SetSlice(cursorIndex[1]);

        this->update_CrossHairLines();

        this->sp_Axial_Viewer->Render();
        this->sp_Sagittal_Viewer->Render();
        this->sp_Coronal_Viewer->Render();
    });

    connect(this->ui->verticalSlider_3, &QSlider::valueChanged, this, [this](int val) {
        this->cursorIndex[1] = val;
        this->sp_Axial_Viewer->SetSlice(cursorIndex[2]);
        this->sp_Sagittal_Viewer->SetSlice(cursorIndex[0]);
        this->sp_Coronal_Viewer->SetSlice(cursorIndex[1]);

        this->update_CrossHairLines();

        this->sp_Axial_Viewer->Render();
        this->sp_Sagittal_Viewer->Render();
        this->sp_Coronal_Viewer->Render();
    });

    connect(this, &View_Dicom::sig_MainWindow_Resize, this, &View_Dicom::slot_MainWindow_Resize);

    this->ui->treeWidget->connect(this->ui->treeWidget,
                                  &QTreeWidget::itemClicked,
                                  this,
                                  &View_Dicom::slot_TreeItem_Clicked);

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

    this->cursorIndex[2] = axial_slice_avgRange;
    this->cursorIndex[1] = coronal_slice_avgRange;
    this->cursorIndex[0] = sagittal_slice_avgRange;

    this->sp_Axial_Viewer->SetSlice(this->cursorIndex[2]);
    this->sp_Coronal_Viewer->SetSlice(this->cursorIndex[1]);
    this->sp_Sagittal_Viewer->SetSlice(this->cursorIndex[0]);

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

    this->update_CrossHairLines();

    this->fix_ViewScale_Width(this->sp_Axial_Viewer,
                              this->ui->QVTK_axialWidget,
                              vtkResliceImageView_Type::AXIAL);
    this->fix_ViewScale_Width(this->sp_Coronal_Viewer,
                              this->ui->QVTK_coronalWidget,
                              vtkResliceImageView_Type::CORONAL);
    this->fix_ViewScale_Width(this->sp_Sagittal_Viewer,
                              this->ui->QVTK_sagittalWidget,
                              vtkResliceImageView_Type::SAGITTAL);

    this->set_UI_slider();

    this->sp_Axial_Viewer->Render();
    this->sp_Coronal_Viewer->Render();
    this->sp_Sagittal_Viewer->Render();

    qDebug() << "Axial slice range:" << this->sp_Axial_Viewer->GetSliceMin()
             << this->sp_Axial_Viewer->GetSliceMax();

    qDebug() << "Coronal slice range:" << this->sp_Coronal_Viewer->GetSliceMin()
             << this->sp_Coronal_Viewer->GetSliceMax();

    qDebug() << "Sagittal slice range:" << this->sp_Sagittal_Viewer->GetSliceMin()
             << this->sp_Sagittal_Viewer->GetSliceMax();

    return;
}

void View_Dicom::slot_Set_First_TreeItem_Position_From_Store()
{
    //====================== 트리 하이라이트 처음 =====================
    //====================== 트리 하이라이트 처음 =====================

    int slice = this->sp_Axial_Viewer->GetSlice();
    int row = this->cnv_Slice_To_Row(slice);
    auto tmp = this->p_vm_Dicom->get_Store_seriesInstanceUID();

    auto parent_Item = this->find_TopLevleItem(this->p_vm_Dicom->get_Store_seriesInstanceUID());
    auto child_Item = parent_Item->child(row);
    if (child_Item != nullptr)
    {
        parent_Item->setExpanded(true);
        this->ui->treeWidget->setCurrentItem(child_Item);
        this->ui->treeWidget->scrollToItem(child_Item);

        this->slot_TreeItem_Clicked(child_Item, 0);
    }
    // this->
    //====================== 트리 하이라이트 처음 =====================
    //====================== 트리 하이라이트 처음 =====================
}

void View_Dicom::set_UI_slider()
{
    // ===================== UI Slider =====================
    QSignalBlocker blk_1(this->ui->verticalSlider);
    QSignalBlocker blk_2(this->ui->verticalSlider_2);
    QSignalBlocker blk_3(this->ui->verticalSlider_3);

    this->ui->verticalSlider->setEnabled(true);
    this->ui->verticalSlider_2->setEnabled(true);
    this->ui->verticalSlider_3->setEnabled(true);

    int axialMin = this->sp_Axial_Viewer->GetSliceMin();
    int axialMax = this->sp_Axial_Viewer->GetSliceMax();
    this->ui->verticalSlider->setRange(0, (axialMax - axialMin));

    this->ui->verticalSlider_2->setRange(this->sp_Sagittal_Viewer->GetSliceMin(),
                                         this->sp_Sagittal_Viewer->GetSliceMax());

    this->ui->verticalSlider_3->setRange(this->sp_Coronal_Viewer->GetSliceMin(),
                                         this->sp_Coronal_Viewer->GetSliceMax());

    // int axial_min = this->sp_Axial_Viewer->GetSliceMin();
    // int axial_max = this->sp_Axial_Viewer->GetSliceMax();
    // this->ui->verticalSlider->setSliderPosition((axial_min + axial_max) / 2);
    int axialCenter = (axialMin + axialMax) / 2;
    int axialRow = this->cnv_Slice_To_Row(axialCenter);
    this->ui->verticalSlider->setValue(axialRow);

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

    // 십자선 초기화
    this->init_CrossHairLines(this->st_Axial_Cross,
                              this->sp_Axial_Viewer->GetRenderer(),
                              crossHairLines_Type::AXIAL);
    this->init_CrossHairLines(this->st_Coronal_Cross,
                              this->sp_Coronal_Viewer->GetRenderer(),
                              crossHairLines_Type::CORONAL);
    this->init_CrossHairLines(this->st_Sagittal_Cross,
                              this->sp_Sagittal_Viewer->GetRenderer(),
                              crossHairLines_Type::SAGITTAL);

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
    // ===================== 슬라이더 Observer =====================
    // ===================== 슬라이더 Observer =====================

    // ===================== Mouse Observer =====================
    // ===================== Mouse Observer =====================
    this->sp_MouseEvent_AxialViewer_Command = vtkSmartPointer<MouseMove_CallBack_VtkCommand>::New();
    this->sp_MouseEvent_AxialViewer_Command->set_p_v_Dicom(this);
    this->sp_MouseEvent_AxialViewer_Command->set_viewType(vtkResliceImageView_Type::AXIAL);
    this->sp_Axial_Viewer->GetRenderWindow()
        ->GetInteractor()
        ->AddObserver(vtkCommand::MouseMoveEvent, this->sp_MouseEvent_AxialViewer_Command);

    this->sp_MouseEvent_SagittalViewer_Command
        = vtkSmartPointer<MouseMove_CallBack_VtkCommand>::New();
    this->sp_MouseEvent_SagittalViewer_Command->set_p_v_Dicom(this);
    this->sp_MouseEvent_SagittalViewer_Command->set_viewType(vtkResliceImageView_Type::SAGITTAL);
    this->sp_Sagittal_Viewer->GetRenderWindow()
        ->GetInteractor()
        ->AddObserver(vtkCommand::MouseMoveEvent, this->sp_MouseEvent_SagittalViewer_Command);

    this->sp_MouseEvent_CoronalViewer_Command = vtkSmartPointer<MouseMove_CallBack_VtkCommand>::New();
    this->sp_MouseEvent_CoronalViewer_Command->set_p_v_Dicom(this);
    this->sp_MouseEvent_CoronalViewer_Command->set_viewType(vtkResliceImageView_Type::CORONAL);
    this->sp_Coronal_Viewer->GetRenderWindow()
        ->GetInteractor()
        ->AddObserver(vtkCommand::MouseMoveEvent, this->sp_MouseEvent_CoronalViewer_Command);

    // ===================== Mouse Observer =====================
    // ===================== Mouse Observer =====================
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
