#include "CallBack_VtkCommand.h"
#include "./View/View_Dicom.h"

CallBack_VtkCommand::CallBack_VtkCommand() {}

CallBack_VtkCommand* CallBack_VtkCommand::New()
{
    return new CallBack_VtkCommand;
}

void CallBack_VtkCommand::set_p_v_Dicom(View_Dicom* set)
{
    this->p_v_Dicom = set;
    return;
}

void CallBack_VtkCommand::set_viewType(vtkResliceImageView_Type set)
{
    this->viewType = set;
}

void CallBack_VtkCommand::Execute(vtkObject* caller, unsigned long eventId, void* callData)
{
    if (this->p_v_Dicom == nullptr)
    {
        qDebug() << "this->p_v_Dicom == nullptr";
        return;
    }

    if (eventId == vtkResliceImageViewer::SliceChangedEvent)
    {
        this->p_v_Dicom->set_ui_slider_vtkCommand(this->viewType);
    }
    return;
}
