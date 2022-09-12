function(structure_only_options)
  set(_options)
  set(_one_value_args)
  set(_multi_value_args LIBRARIES INCLUDES)

  cmake_parse_arguments(_args
    "${_options}"
    "${_one_value_args}"
    "${_multi_value_args}"
    ${ARGN}
  )

  if(NOT TARGET structure_only_options)
    add_library(structure_only_options INTERFACE)
  endif()

  target_link_libraries(structure_only_options
    INTERFACE
    ${_args_LIBRARIES}
  )
  target_include_directories(structure_only_options
    INTERFACE
    ${_args_INCLUDES}
  )
endfunction()

function(structure_only)
  set(_options)
  set(_one_value_args)
  set(_multi_value_args DIRECTORIES)

  cmake_parse_arguments(_args "${_options}" "${_one_value_args}"
    "${_multi_value_args}" ${ARGN})

  if(NOT TARGET structure_only)
    add_executable(structure_only)
  endif()

  if(NOT TARGET structure_only_options)
    add_library(structure_only_options INTERFACE)
  endif()

  foreach(directory IN LISTS _args_DIRECTORIES)
    set(expression h hpp hh c cc cxx cpp)
    list(TRANSFORM expression PREPEND "${directory}/*.")

    file(GLOB_RECURSE files
      FOLLOW_SYMLINKS
      LIST_DIRECTORIES false
      ${expression}
    )

    target_sources(structure_only
      PRIVATE
      ${files}
    )
    target_link_libraries(structure_only
      PRIVATE
      project_options
      project_warnings
      structure_only_options
    )
  endforeach()
endfunction()