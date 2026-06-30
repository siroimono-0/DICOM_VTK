#include "CallBack_VtkCommand.h"
#include "./View/View_Dicom.h"

MouseMove_CallBack_VtkCommand::MouseMove_CallBack_VtkCommand()
{
    return;
}

MouseMove_CallBack_VtkCommand* MouseMove_CallBack_VtkCommand::New()
{
    return new MouseMove_CallBack_VtkCommand();
}

void MouseMove_CallBack_VtkCommand::set_p_v_Dicom(View_Dicom* set)
{
    this->p_v_Dicom = set;
    return;
}

void MouseMove_CallBack_VtkCommand::set_viewType(const vtkResliceImageView_Type set)
{
    this->viewType = set;
    return;
}

void MouseMove_CallBack_VtkCommand::Execute(vtkObject* caller, unsigned long eventId, void* callData)
{
    if (eventId != vtkCommand::MouseMoveEvent)
    {
        return;
    }

    auto interactor = vtkRenderWindowInteractor::SafeDownCast(caller);

    if (interactor == nullptr)
    {
        return;
    }

    int* pos = interactor->GetEventPosition();
    int x = pos[0];
    int y = pos[1];

    this->p_v_Dicom->set_UI_YX_vtkCommand(y, x, this->viewType);
}
//===================================================================
//===================================================================
//===================================================================
//===================================================================
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
        this->p_v_Dicom->set_UI_slider_vtkCommand(this->viewType);
        this->p_v_Dicom->set_UI_ImageCountLabel_VtkCommand(this->viewType);
    }
    return;
}
