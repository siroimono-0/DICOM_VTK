#include "View_Dia_Win_Level_Set.h"
#include "View/ui_View_Dia_Win_Level_Set.h"

View_Dia_Win_Level_Set::View_Dia_Win_Level_Set(VM_Dicom *set, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::View_Dia_Win_Level_Set)
{
    ui->setupUi(this);
    this->p_vm_Dicom = set;
    this->init_Connect();
}

void View_Dia_Win_Level_Set::init_First_Value(int mmin, int mmax, int window, int level)
{
    QSignalBlocker block_1(this->ui->window_HorizontalSlider);
    QSignalBlocker block_2(this->ui->level_HorizontalSlider);

    this->ui->window_HorizontalSlider->setRange(mmin, mmax);
    this->ui->level_HorizontalSlider->setRange(mmin, mmax);

    this->ui->window_HorizontalSlider->setValue(window);
    this->ui->window_LineEdit->setText(QString::number(window));
    this->ui->window_Left_Label->setText(QString::number(mmin));
    this->ui->window_Right_Label->setText(QString::number(mmax));

    this->ui->level_HorizontalSlider->setValue(level);
    this->ui->level_LineEdit->setText(QString::number(level));
    this->ui->level_Left_Label->setText(QString::number(mmin));
    this->ui->level_Right_Label->setText(QString::number(mmax));

    return;
}

void View_Dia_Win_Level_Set::slot_SetLineEdit_Window_sliderMoved(int set)
{
    QSignalBlocker block_1(this->ui->window_LineEdit);
    this->ui->window_LineEdit->setText(QString::number(set));
    return;
}

void View_Dia_Win_Level_Set::slot_SetLineEdit_Level_sliderMoved(int set)
{
    QSignalBlocker block_1(this->ui->level_LineEdit);
    this->ui->level_LineEdit->setText(QString::number(set));
    return;
}

void View_Dia_Win_Level_Set::init_Connect()
{
    connect(this->ui->window_HorizontalSlider,
            &QSlider::sliderMoved,
            this,
            &View_Dia_Win_Level_Set::sig_Change_Window);

    connect(this->ui->level_HorizontalSlider,
            &QSlider::sliderMoved,
            this,
            &View_Dia_Win_Level_Set::sig_Change_Level);

    connect(this->ui->window_HorizontalSlider,
            &QSlider::sliderMoved,
            this,
            &View_Dia_Win_Level_Set::slot_SetLineEdit_Window_sliderMoved);

    connect(this->ui->level_HorizontalSlider,
            &QSlider::sliderMoved,
            this,
            &View_Dia_Win_Level_Set::slot_SetLineEdit_Level_sliderMoved);

    connect(this->ui->window_LineEdit, &QLineEdit::textChanged, ) return;
}

View_Dia_Win_Level_Set::~View_Dia_Win_Level_Set()
{
    delete ui;
}
