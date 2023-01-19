include_guard()

include(MyProjectOptions)

# structure_only_options(
# [LIBRARIES [lib1 lib2 ...]]
# [INCLUDES [include1 include2 ...]]
# )
#
# add new libraries and includes for all files that target `structure_only` handles
function(structure_only_options)
  set(options)
  set(one_value_args)
  set(multi_value_args LIBRARIES INCLUDES)

  cmake_parse_arguments(args "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  if(NOT TARGET structure_only_options)
    add_library(structure_only_options INTERFACE)
  endif()

  target_link_system_libraries(structure_only_options INTERFACE ${args_LIBRARIES})
  target_include_system_directories(structure_only_options INTERFACE ${args_INCLUDES})
endfunction()

# structure_only(
# [DIRECTORIES [directory1 directory2 ...]]
# )
#
# add files in directories to target `structure_only`
function(structure_only)
  set(options)
  set(one_value_args)
  set(multi_value_args DIRECTORIES)

  cmake_parse_arguments(args "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  if(NOT TARGET structure_only)
    add_executable(structure_only)
  endif()

  if(NOT TARGET structure_only_options)
    add_library(structure_only_options INTERFACE)
  endif()

  foreach(directory IN LISTS args_DIRECTORIES)
    set(expression
      h
      hpp
      hh
      c
      cc
      cxx
      cpp
    )
    list(TRANSFORM expression PREPEND "${directory}/*.")

    file(
      GLOB_RECURSE files FOLLOW_SYMLINKS
      LIST_DIRECTORIES false
      ${expression}
    )

    target_sources(structure_only PRIVATE ${files})
    target_link_libraries(structure_only PRIVATE project_options project_warnings structure_only_options)
  endforeach()
endfunction()
