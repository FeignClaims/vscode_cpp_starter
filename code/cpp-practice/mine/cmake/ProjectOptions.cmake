include_guard()

message(STATUS "Downloading ProjectOptions from https://github.com/aminya/project_options.git\n"
  "Please make sure that you can connect to github"
)
include(FetchContent)
FetchContent_Declare(_project_options
  GIT_REPOSITORY https://github.com/aminya/project_options.git
  GIT_TAG main
  GIT_SHALLOW true
)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)
include(${_project_options_SOURCE_DIR}/src/DynamicProjectOptions.cmake)
