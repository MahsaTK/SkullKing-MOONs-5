# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\game__autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\game__autogen.dir\\ParseCache.txt"
  "game__autogen"
  )
endif()
