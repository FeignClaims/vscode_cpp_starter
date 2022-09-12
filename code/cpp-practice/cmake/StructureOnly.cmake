function(structure_only_options)
  set(options)
  set(oneValueArgs)
  set(multiValueArgs LIBRARIES INCLUDES)

  cmake_parse_arguments(STRUCTURE_ONLY_OPTIONS "${options}" "${oneValueArgs}"
    "${multiValueArgs}" ${ARGN})

  if(NOT TARGET structure_only_options)
    add_library(structure_only_options INTERFACE)
  endif()

  target_link_libraries(structure_only_options
    INTERFACE
    ${STRUCTURE_ONLY_OPTIONS_LIBRARIES}
  )
  target_include_directories(structure_only_options
    INTERFACE
    ${STRUCTURE_ONLY_OPTIONS_INCLUDES}
  )
endfunction()

function(structure_only)
  set(options)
  set(oneValueArgs)
  set(multiValueArgs DIRECTORIES)

  cmake_parse_arguments(STRUCTURE_ONLY "${options}" "${oneValueArgs}"
    "${multiValueArgs}" ${ARGN})

  if(NOT TARGET structure_only)
    add_executable(structure_only)
  endif()

  if(NOT TARGET structure_only_options)
    add_library(structure_only_options INTERFACE)
  endif()

  foreach(directory IN LISTS STRUCTURE_ONLY_DIRECTORIES)
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