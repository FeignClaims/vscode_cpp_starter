cmake_minimum_required(VERSION 3.24)
project(vscode-llvm-cpp-starter LANGUAGES NONE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/include")

file(GLOB_RECURSE files CONFIGURE_DEPENDS ".DS_Store")
list(APPEND files
  ${CMAKE_CURRENT_SOURCE_DIR}/code/cpp-practice/.cache
  ${CMAKE_CURRENT_SOURCE_DIR}/code/cpp-practice/build
  ${CMAKE_CURRENT_SOURCE_DIR}/code/cpp-practice/compile_commands.json
  ${CMAKE_CURRENT_SOURCE_DIR}/docs/build
)
add_custom_target(clear_temporary_files ALL
  COMMAND ${CMAKE_COMMAND} -E rm -rf ${files}
)

add_custom_target(run ALL)

function(compress path)
  cmake_path(GET path FILENAME filename)
  cmake_path(GET path PARENT_PATH parent_path)
  add_custom_command(TARGET run PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E tar c temp_${filename}.zip --format=zip ${filename}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different temp_${filename}.zip ${filename}.zip
    COMMAND ${CMAKE_COMMAND} -E rm -rf temp_${filename}.zip
    DEPENDS clear_temporary_files
    WORKING_DIRECTORY ${parent_path}
  )
endfunction()

compress(${CMAKE_CURRENT_SOURCE_DIR}/code/cpp-practice)
compress(${CMAKE_CURRENT_SOURCE_DIR}/code/my_utility)