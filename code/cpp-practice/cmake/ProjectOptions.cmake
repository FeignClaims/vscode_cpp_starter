# https://github.com/aminya/project_options
include_guard()

message(
  STATUS
  "Downloading ProjectOptions from https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/raw/master/project_options.zip"
)
include(FetchContent)
FetchContent_Declare(_project_options
  URL https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/raw/master/project_options.zip
)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)
include(${_project_options_SOURCE_DIR}/src/DynamicProjectOptions.cmake)
