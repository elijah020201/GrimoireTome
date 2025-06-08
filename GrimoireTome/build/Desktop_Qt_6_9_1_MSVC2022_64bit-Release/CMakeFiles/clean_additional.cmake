# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\GrimoireTome_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GrimoireTome_autogen.dir\\ParseCache.txt"
  "GrimoireTome_autogen"
  )
endif()
