#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include <QObject>
#include "./Service/Service_Dicom.h"
#include "./Store/Store_Dicom.h"
#include "./View/View_Dia_Win_Level_Set.h"
#include "./View/View_Dicom.h"
#include "./ViewModel/VM_Dicom.h"

class AppContext : public QObject
{
    Q_OBJECT
public:
    explicit AppContext(QObject *parent = nullptr);
    ~AppContext();

    View_Dicom *get_p_v_Dicom();

    void init_p_st_Dicom();
    void init_p_svc_Dicom();
    void init_p_vm_Dicom();
    void init_p_v_Dicom();
    // void init_p_v_Dia_WinLevelSetting();

    void init_connect_p_svc_Dicom_To_p_vm_Dicom();

    void init_connect_p_st_Dicom_To_p_v_Dicom();

public slots:

signals:

private:
    View_Dicom *p_v_Dicom = nullptr;
    VM_Dicom *p_vm_Dicom = nullptr;
    Service_Dicom *p_svc_Dicom = nullptr;
    Store_Dicom *p_st_Dicom = nullptr;
    // View_Dia_Win_Level_Set *p_v_Dia_WinLevelSetting = nullptr;

    //=======================SERVICE=======================
    //=======================SERVICE=======================

    //=======================SERVICE=======================
    //=======================SERVICE=======================
};

#endif // APPCONTEXT_H
