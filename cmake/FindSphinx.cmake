macro(_Sphinx_find_sphinx_build)
  find_program(SPHINX_BUILD_EXECUTABLE
    NAMES sphinx-build
    DOC "Sphinx build tool"
  )
  mark_as_advanced(SPHINX_BUILD_EXECUTABLE)

  if(SPHINX_BUILD_EXECUTABLE)
    if(NOT TARGET sphinx::build)
      add_executable(sphinx::build IMPORTED GLOBAL)
      set_target_properties(sphinx::build PROPERTIES
        IMPORTED_LOCATION "${SPHINX_BUILD_EXECUTABLE}"
      )
    endif()
  endif()
endmacro()

macro(_Sphinx_find_sphinx_autobuild)
  find_program(SPHINX_AUTOBUILD_EXECUTABLE
    NAMES sphinx-autobuild
    DOC "Sphinx autobuild tool"
  )
  mark_as_advanced(SPHINX_AUTOBUILD_EXECUTABLE)

  if(SPHINX_AUTOBUILD_EXECUTABLE)
    if(NOT TARGET sphinx::autobuild)
      add_executable(sphinx::autobuild IMPORTED GLOBAL)
      set_target_properties(sphinx::autobuild PROPERTIES
        IMPORTED_LOCATION "${SPHINX_AUTOBUILD_EXECUTABLE}"
      )
    endif()
  endif()
endmacro()

if(NOT Sphinx_FIND_COMPONENTS)
  set(Sphinx_FIND_COMPONENTS build autobuild)
endif()

foreach(_comp IN LISTS Sphinx_FIND_COMPONENTS)
  if(_comp STREQUAL "build")
    _Sphinx_find_sphinx_build()
  elseif(_comp STREQUAL "autobuild")
    _Sphinx_find_sphinx_autobuild()
  else()
    message(WARNING "${_comp} is not a valid Sphinx component")
  endif()

  if(TARGET sphinx::${_comp})
    set(Doxygen_${_comp}_FOUND TRUE)
  else()
    set(Doxygen_${_comp}_FOUND FALSE)
  endif()
endforeach()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(Sphinx
  REQUIRED_VARS SPHINX_BUILD_EXECUTABLE SPHINX_AUTOBUILD_EXECUTABLE
)

function(sphinx_add_docs target_name)
  set(_options USE_STAMP_FILE)
  set(_one_value_args SOURCE_DIR BUILD_DIR COMMENT WORKING_DIRECTORY)
  set(_multi_value_args)
  cmake_parse_arguments(_args
    "${_options}"
    "${_one_value_args}"
    "${_multi_value_args}"
    ${ARGN}
  )

  if(NOT _args_SOURCE_DIR)
    message(FATAL_ERROR "No SOURCE_DIR given to sphinx_add_docs()")
  endif()

  if(NOT _args_BUILD_DIR)
    message(WARNING "No BUILD_DIR given to sphinx, default to ${CMAKE_CURRENT_BINARY_DIR}")
    set(_args_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
  endif()

  if(NOT _args_COMMENT)
    set(_args_COMMENT "Generate documentation for ${target_name}")
  endif()

  if(NOT _args_WORKING_DIRECTORY)
    set(_args_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
  endif()

  set(__stamp_file "${CMAKE_CURRENT_BINARY_DIR}/${target_name}.stamp")
  add_custom_command(
    VERBATIM
    OUTPUT ${__stamp_file}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${_args_BUILD_DIR}
    COMMAND sphinx::build "${_args_SOURCE_DIR}" "${_args_BUILD_DIR}"
    COMMAND "${CMAKE_COMMAND}" -E touch ${__stamp_file}
    WORKING_DIRECTORY "${_args_WORKING_DIRECTORY}"
    DEPENDS ${_args_SOURCE_DIR}
    COMMENT ${_args_COMMENT}
  )
  add_custom_target(sphinx-${target_name}
    DEPENDS ${__stamp_file}
    SOURCES ${_args_SOURCE_DIR}
  )

  add_custom_target(sphinx_auto-${target_name}
    VERBATIM
    COMMAND ${CMAKE_COMMAND} -E make_directory ${_args_BUILD_DIR}
    COMMAND sphinx::autobuild "${_args_SOURCE_DIR}" "${_args_BUILD_DIR}"
    WORKING_DIRECTORY "${_args_WORKING_DIRECTORY}"
    DEPENDS ${_args_SOURCE_DIR}
    COMMENT ${_args_COMMENT}
    SOURCES ${_args_SOURCE_DIR}
    USES_TERMINAL
  )
endfunction()