cmake_minimum_required(VERSION 3.0)

project(qt-activex-example)

add_subdirectory(activex)

if(CMAKE_PREFIX_PATH)
  add_subdirectory(qt)
endif()
