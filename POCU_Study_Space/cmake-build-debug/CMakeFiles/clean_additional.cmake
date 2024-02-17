# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\POCU_Study_Space_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\POCU_Study_Space_autogen.dir\\ParseCache.txt"
  "POCU_Study_Space_autogen"
  )
endif()
