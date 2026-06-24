#ifndef CALLBACK_VTKCOMMAND_H
#define CALLBACK_VTKCOMMAND_H

#include <QDebug>
#include <QSignalBlocker>
#include "./Common.h"
#include <vtkCommand.h>
#include <vtkResliceImageViewer.h>

class View_Dicom;

class CallBack_VtkCommand : public vtkCommand
{
public:
    CallBack_VtkCommand();

    static CallBack_VtkCommand* New();
    void set_p_v_Dicom(View_Dicom* set);
    void set_viewType(const vtkResliceImageView_Type set);

    void Execute(vtkObject* caller, unsigned long eventId, void* callData) override;

private:
    View_Dicom* p_v_Dicom = nullptr;
    vtkResliceImageView_Type viewType;
};

#endif // CALLBACK_VTKCOMMAND_H
