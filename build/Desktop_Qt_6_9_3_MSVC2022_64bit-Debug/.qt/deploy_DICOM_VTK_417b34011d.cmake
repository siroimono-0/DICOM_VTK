include("C:/Users/siroi/siroimono/w_qt/DICOM_VTK/build/Desktop_Qt_6_9_3_MSVC2022_64bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/DICOM_VTK-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "C:/Users/siroi/siroimono/w_qt/DICOM_VTK/build/Desktop_Qt_6_9_3_MSVC2022_64bit-Debug/DICOM_VTK.exe"
    GENERATE_QT_CONF
)
