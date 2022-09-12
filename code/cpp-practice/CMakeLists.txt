cmake_minimum_required(VERSION 3.22)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GetProjectOptions)

project(cpp-practice LANGUAGES CXX)

include(MyProjectOptions)

include(StructureOnly)
structure_only(
  DIRECTORIES
  src
  test
)