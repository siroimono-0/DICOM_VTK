cmake_minimum_required(VERSION 3.19)
project(DICOM_VTK LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets OpenGLWidgets)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set(VTK_DIR "C:/Users/siroi/siroimono/w_qt/Dicom_demo/VTK-9.6.2/VTK-9.6.2/build/Desktop_Qt_6_9_3_MSVC2022_64bit-Debug/lib/cmake/vtk-9.6")

set(DCMTK_DIR "C:/Users/siroi/dcmtk-install/cmake")


find_package(DCMTK CONFIG REQUIRED)

find_package(VTK REQUIRED COMPONENTS
    CommonCore
    CommonDataModel
    IOImage
    RenderingCore
    RenderingOpenGL2
    RenderingFreeType
    InteractionStyle
    InteractionImage
    InteractionWidgets
    GUISupportQt
)

qt_standard_project_setup()

qt_add_executable(DICOM_VTK
    WIN32 MACOSX_BUNDLE
    main.cpp
    Service/Service_Dicom.h
    Service/Service_Dicom.cpp
    AppContext.h AppContext.cpp
    View/View_Dicom.h
    View/View_Dicom.cpp
    View/View_Dicom.ui
    ViewModel/VM_Dicom.h
    ViewModel/VM_Dicom.cpp
    Interface/I_Dicom_Common.h
    Store/Store_Dicom.h
    Store/Store_Dicom.cpp
    Common.h
    CallBack_VtkCommand.h CallBack_VtkCommand.cpp
    Service/WK_Dicom_1.h Service/WK_Dicom_1.cpp
    View/View_Dia_Win_Level_Set.h
    View/View_Dia_Win_Level_Set.cpp
    View/View_Dia_Win_Level_Set.ui
)

qt_add_resources(
    DICOM_VTK "img"
    PREFIX "/"
    FILES
        ./image/time.svg
)

target_compile_definitions(DICOM_VTK PRIVATE NOMINMAX)

target_link_libraries(DICOM_VTK
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::OpenGLWidgets
        ${VTK_LIBRARIES}
)
target_link_libraries(DICOM_VTK PRIVATE Qt6::Core)
target_link_libraries(DICOM_VTK PRIVATE Qt6::Concurrent)

target_include_directories(${PROJECT_NAME} PRIVATE
    "C:/Users/siroi/dcmtk-install/include"
)

target_link_directories(${PROJECT_NAME} PRIVATE
    "C:/Users/siroi/dcmtk-install/lib"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    dcmdata
    oflog
    ofstd
    oficonv
    iphlpapi
    netapi32
)

include(GNUInstallDirs)

install(TARGETS DICOM_VTK
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET DICOM_VTK
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
