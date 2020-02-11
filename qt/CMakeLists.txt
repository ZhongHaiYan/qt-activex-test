
find_package(Qt5 5.6.3 REQUIRED AxContainer)

add_executable(activex
  foobarocx.cpp foobarocx.h
  main.cc)

target_link_libraries(activex Qt5::AxContainer Qt5::Core)
