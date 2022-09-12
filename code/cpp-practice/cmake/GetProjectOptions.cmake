# https://github.com/aminya/project_options

set(project_options_dir ${CMAKE_CURRENT_LIST_DIR}/project_options)

include(${project_options_dir}/Index.cmake)

# 提供一系列推荐的默认设置
include(${project_options_dir}/src/DynamicProjectOptions.cmake)