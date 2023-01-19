include_guard()

function(target_library_include target)
  set(${target}_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE STRING "" FORCE)

  get_target_property(sources ${target} SOURCES)

  if(NOT sources) # header-only library
    target_include_directories(${target}
      INTERFACE
      $<BUILD_INTERFACE:${${target}_INCLUDE_DIR}>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    )
  else()
    target_include_directories(${target}
      PUBLIC
      $<BUILD_INTERFACE:${${target}_INCLUDE_DIR}>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    )
  endif()
endfunction()

function(target_configure_dependencies target)
  set(options)
  set(one_value_args)
  set(multi_value_args PRIVATE PUBLIC INTERFACE)

  cmake_parse_arguments(args "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  set(${target}_PRIVATE_DEPENDENCIES_CONFIGURED ${args_PRIVATE} CACHE STRING "" FORCE)
  set(${target}_PUBLIC_DEPENDENCIES_CONFIGURED ${args_PUBLIC} CACHE STRING "" FORCE)
  set(${target}_INTERFACE_DEPENDENCIES_CONFIGURED ${args_INTERFACE} CACHE STRING "" FORCE)

  foreach(dependency IN LISTS args_PRIVATE args_PUBLIC args_INTERFACE)
    find_package(${dependency} CONFIG REQUIRED)
  endforeach()
endfunction()