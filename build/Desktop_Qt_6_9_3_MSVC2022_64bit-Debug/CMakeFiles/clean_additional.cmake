# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DICOM_VTK_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DICOM_VTK_autogen.dir\\ParseCache.txt"
  "DICOM_VTK_autogen"
  )
endif()
