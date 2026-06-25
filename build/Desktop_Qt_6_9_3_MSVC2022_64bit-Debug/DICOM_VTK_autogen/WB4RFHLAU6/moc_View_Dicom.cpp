/****************************************************************************
** Meta object code from reading C++ file 'View_Dicom.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../View/View_Dicom.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'View_Dicom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10View_DicomE_t {};
} // unnamed namespace

template <> constexpr inline auto View_Dicom::qt_create_metaobjectdata<qt_meta_tag_ZN10View_DicomE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "View_Dicom",
        "sig_MainWindow_Resize",
        "",
        "slot_Action_FileOpen_Clicked",
        "slot_Action_DirectoryOpen_Clicked",
        "slot_DicomFile_Reload_From_Store",
        "slot_MainWindow_Resize",
        "slot_Axial_RollBtn_Left_Clicked",
        "slot_Axial_RollBtn_Right_Clicked",
        "slot_Coronal_RollBtn_Left_Clicked",
        "slot_Coronal_RollBtn_Right_Clicked",
        "slot_Sagittal_RollBtn_Left_Clicked",
        "slot_Sagittal_RollBtn_Right_Clicked",
        "slot_Axial_FlipBtn_Horizontal_Clicked",
        "slot_Axial_FlipBtn_Vertical_Clicked",
        "slot_Coronal_FlipBtn_Horizontal_Clicked",
        "slot_Coronal_FlipBtn_Vertical_Clicked",
        "slot_Sagittal_FlipBtn_Horizontal_Clicked",
        "slot_Sagittal_FlipBtn_Vertical_Clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sig_MainWindow_Resize'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Action_FileOpen_Clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Action_DirectoryOpen_Clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_DicomFile_Reload_From_Store'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_MainWindow_Resize'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Axial_RollBtn_Left_Clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Axial_RollBtn_Right_Clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Coronal_RollBtn_Left_Clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Coronal_RollBtn_Right_Clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Sagittal_RollBtn_Left_Clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Sagittal_RollBtn_Right_Clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Axial_FlipBtn_Horizontal_Clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Axial_FlipBtn_Vertical_Clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Coronal_FlipBtn_Horizontal_Clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Coronal_FlipBtn_Vertical_Clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Sagittal_FlipBtn_Horizontal_Clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slot_Sagittal_FlipBtn_Vertical_Clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<View_Dicom, qt_meta_tag_ZN10View_DicomE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject View_Dicom::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10View_DicomE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10View_DicomE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10View_DicomE_t>.metaTypes,
    nullptr
} };

void View_Dicom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<View_Dicom *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sig_MainWindow_Resize(); break;
        case 1: _t->slot_Action_FileOpen_Clicked(); break;
        case 2: _t->slot_Action_DirectoryOpen_Clicked(); break;
        case 3: _t->slot_DicomFile_Reload_From_Store(); break;
        case 4: _t->slot_MainWindow_Resize(); break;
        case 5: _t->slot_Axial_RollBtn_Left_Clicked(); break;
        case 6: _t->slot_Axial_RollBtn_Right_Clicked(); break;
        case 7: _t->slot_Coronal_RollBtn_Left_Clicked(); break;
        case 8: _t->slot_Coronal_RollBtn_Right_Clicked(); break;
        case 9: _t->slot_Sagittal_RollBtn_Left_Clicked(); break;
        case 10: _t->slot_Sagittal_RollBtn_Right_Clicked(); break;
        case 11: _t->slot_Axial_FlipBtn_Horizontal_Clicked(); break;
        case 12: _t->slot_Axial_FlipBtn_Vertical_Clicked(); break;
        case 13: _t->slot_Coronal_FlipBtn_Horizontal_Clicked(); break;
        case 14: _t->slot_Coronal_FlipBtn_Vertical_Clicked(); break;
        case 15: _t->slot_Sagittal_FlipBtn_Horizontal_Clicked(); break;
        case 16: _t->slot_Sagittal_FlipBtn_Vertical_Clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (View_Dicom::*)()>(_a, &View_Dicom::sig_MainWindow_Resize, 0))
            return;
    }
}

const QMetaObject *View_Dicom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View_Dicom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10View_DicomE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int View_Dicom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void View_Dicom::sig_MainWindow_Resize()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
