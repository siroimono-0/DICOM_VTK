#ifndef VIEW_DIA_WIN_LEVEL_SET_H
#define VIEW_DIA_WIN_LEVEL_SET_H

#include <QDialog>
class VM_Dicom;

namespace Ui {
class View_Dia_Win_Level_Set;
}

class View_Dia_Win_Level_Set : public QDialog
{
    Q_OBJECT

public:
    explicit View_Dia_Win_Level_Set(VM_Dicom *set, QWidget *parent = nullptr);
    ~View_Dia_Win_Level_Set();

    void init_First_Value(int mmin, int mmax, int window, int level);
    void init_Connect();

public slots:
    // void slot_set_Windows(int position);
    void slot_SetLineEdit_Window_sliderMoved(int set);
    void slot_SetLineEdit_Level_sliderMoved(int set);

    void slot_WindowLineEdit_TextChanged(const QString s);
    void slot_LevelLineEdit_TextChanged(const QString s);

signals:
    void sig_Change_Window(int val);
    void sig_Change_Level(int val);

private:
    Ui::View_Dia_Win_Level_Set *ui;
    VM_Dicom *p_vm_Dicom = nullptr;
};

#endif // VIEW_DIA_WIN_LEVEL_SET_H
