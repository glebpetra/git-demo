# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Bio_3_autogen"
  "CMakeFiles\\Bio_3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Bio_3_autogen.dir\\ParseCache.txt"
  )
endif()
