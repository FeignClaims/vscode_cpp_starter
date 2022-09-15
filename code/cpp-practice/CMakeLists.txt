cmake_minimum_required(VERSION 3.22)
project(cpp-practice LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(MyProjectOptions)
include(SymlinkCompileCommands)

include(StructureOnly)
structure_only(
  DIRECTORIES
  src
  test
)