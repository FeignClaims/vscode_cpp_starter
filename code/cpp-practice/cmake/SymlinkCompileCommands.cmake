execute_process(
  COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json
)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json
    )
  endif()
endif()