set(MIDL_OUTPUT
  ${CMAKE_CURRENT_BINARY_DIR}/FooBarOcx.h
  ${CMAKE_CURRENT_BINARY_DIR}/FooBarOcx_i.c)

set(MIDL_FILE ${CMAKE_CURRENT_LIST_DIR}/FooBarOcx.idl)
add_custom_command(
  OUTPUT ${MIDL_OUTPUT}
  COMMAND midl /char signed /env win32 /Oicf /h FooBarOcx.h /iid FooBarOcx_i.c /no_robust ${MIDL_FILE}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS ${MIDL_FILE}
  MAIN_DEPENDENCY ${MIDL_FILE}
  VERBATIM)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_definitions(-DNDEBUG -DWIN32 -D_WINDOWS -D_USRDLL -D_WINDLL -D_AFXDLL -D_UNICODE -DUNICODE)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /DEF:${CMAKE_CURRENT_SOURCE_DIR}/FooBarOcx.def")

add_library(FooBarOcx SHARED)
target_sources(FooBarOcx
  PRIVATE
    ${MIDL_FILE} ${MIDL_OUTPUT}
    FooBar.cc FooBar.h
    FooBarOcx.cc FooBarOcx.rc
    Resource.h
    stdafx.cc stdafx.h)


function(msvc_convert_vc_ver msvc_vc_ver)
  if("x${CMAKE_CXX_COMPILER_ID}" STREQUAL "xMSVC")
    if    (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 13)
      set(_vc_ver "60")
    elseif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 13.10)
      set(_vc_ver "70")
    elseif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 14)
      set(_vc_ver "71")
    elseif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 15)
      set(_vc_ver "80")
    elseif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 16)
      set(_vc_ver "90")
    elseif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 17)
      set(_vc_ver "100")
    elseif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 18)
      set(_vc_ver "110")
    elseif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19)
      set(_vc_ver "120")
    elseif(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.10)
      set(_vc_ver "140")
    else()
      set(_vc_ver "141")
    endif()
    set(${msvc_vc_ver} ${_vc_ver} PARENT_SCOPE)
  endif()
endfunction()

msvc_convert_vc_ver(MSVC_VC_VER)
set(MFC_SU_LIB "mfcs${MSVC_VC_VER}u.lib")

target_link_libraries(FooBarOcx RpcRT4.lib ${MFC_SU_LIB})
