set(MIDL_OUTPUT
  ${CMAKE_CURRENT_BINARY_DIR}/IFace.h
  ${CMAKE_CURRENT_BINARY_DIR}/GUIDS.c
  ${CMAKE_CURRENT_BINARY_DIR}/Proxy.c
  ${CMAKE_CURRENT_BINARY_DIR}/ProxyDll.c
)
set(MIDL_FILE ${CMAKE_CURRENT_LIST_DIR}/foo.idl)
add_custom_command(
  OUTPUT ${MIDL_OUTPUT}
  COMMAND midl /h IFace.h /iid GUIDS.c /proxy Proxy.c /dlldata ProxyDll.c ${MIDL_FILE}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS ${MIDL_FILE}
  MAIN_DEPENDENCY ${MIDL_FILE}
  VERBATIM
)
# add_custom_target(midl-cmplr
#     DEPENDS ${MIDL_OUTPUT}
# )
# add_dependencies(${PROJECT_NAME}
#     midl-cmplr
# )
# set_source_files_properties(${MIDL_OUTPUT} PROPERTIES
#   GENERATED TRUE
# )
add_library(activex SHARED)
target_sources(activex PRIVATE ${MIDL_FILE} ${MIDL_OUTPUT})
