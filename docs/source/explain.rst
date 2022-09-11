#####
解释
#####

.. include:: /_include/links.rst

摸了，以下为一些配置文件的说明，建议从上到下依次阅读。

.. code-block:: txt

  根目录
  |
  +-- .clang-format
  +-- .clang-tidy
  +-- .clangd
  +-- compile_commands.json
  +-- CMakeLists.txt
  +-- cmake
  |   +-- GetProjectOptions.cmake
  |   +-- MyProjectOptions.cmake
  |   +-- SymlinkCompileCommands.cmake
  +-- .vscode
      +-- extensions.json
      +-- tasks.json
      +-- launch.json
  

.clang-format
*******************

代码自动格式化工具 clang-format 的配置文件。

- 文档见 `Clang-Format 配置选项列表`_。

.clang-tidy
*****************

代码检查工具 clang-tidy 的配置文件，辅助程序员写更优秀的代码。

- 该文件实际并没有被使用而由 ``.clangd`` 文件代劳，这里给出来方便之后学习 CMake。
- 文档见 `Clang-Tidy 诊断选项列表`_。

.clangd
*************

clangd 的配置文件，为程序员提供内联提示、语法高亮等辅助功能，同时内置了 clang-tidy 的功能。

- 文档见 `Clang-Tidy 诊断选项列表`_ 和 `Clangd 官网`_。

compile_commands.json
***************************

该文件在 CMake 进行配置操作后才生成，存储源文件的编译信息，clangd 需要这些信息才能更好地解析代码和理清文件间的关系。

- 根目录下的是该文件的快捷方式，以供 clangd 找到该文件。
- 为减少初学者负担，此处编译信息是假定所有源文件最终编译成一个可执行文件，故编程时 clangd 给出的提示包含整个【cpp-practice】文件夹中的源代码信息，而重命名功能可能影响整个【cpp-practice】文件夹；实际影响不大。
- CMake 的学习可参考 :doc:`special_announcement`。

CMakeLists.txt
********************

CMake 的项目配置文件，这里只用来生成 ``compile_commands.json``。

- 为减少初学者负担，此处 CMake 假定所有源文件最终编译成一个可执行文件，故编程时 clangd 给出的提示包含整个【cpp-practice】文件夹中的源代码信息，而重命名功能可能影响整个【cpp-practice】文件夹；实际影响不大。
- CMake 的学习可参考 :doc:`special_announcement`。

cmake/
***********

CMake 的分文件和一些脚本文件，分文件会在 ``CMakeLists.txt`` 中用 ``include(文件)`` 包含，相当于 C++ 中的 ``#include``。

考虑到读者的环境和网络条件，与我自用的版本有些差异：

- 所使用的开源项目 `Github: aminya/project_options`_ 已预先下载。
- 代码检查工具、文档生成工具等已禁用；在 ``mine/`` 文件夹下，有我使用的版本。
- CMake 的学习可参考 :doc:`special_announcement`

GetProjectOptions.cmake
=============================

获取开源项目 `Github: aminya/project_options`_，考虑到网络条件，已预先下载到 ``project_options`` 文件夹中。

MyProjectOptions.cmake
============================

对 ``project_options`` 进行自定义设置。

- 禁用代码检查工具、文档生成工具等。
- 启用更多的编译器诊断选项，这些选项会被保存到 ``compile_commands.json`` 中，提供给 clangd 进行解析。

SymlinkCompileCommands.cmake
==================================

在包含（ ``include()`` ）该文件的 ``CMakeLists.txt`` 文件所在目录下创建 ``compile_commands.json`` 的快捷方式。

- 创建这个快捷方式便于 clangd 找到 ``compile_commands.json``，兼容源外构建。
- 仅当 CMake 生成器为 Makefiles 或 Ninja 时有效，文中配置已默认设置为 Ninja。（用 ``cmake -S <source> -B <build> -G <generator>`` 来指定， ``cmake --help`` 可查看当前环境可用生成器。）

mine/
=======

我使用的版本，为此需要安装一下软件：

.. code-block:: txt

  conan  # 包管理工具
  include-what-you-use  # 缩写为 iwyu
  ccache  # 通过缓存加快编译
  doxygen  # 文档生成工具
  cppcheck  # 一个代码检查工具

.vscode/
*****************************
  
该文件夹特定的 VSCode 配置，仅在当前文件夹下有效。

extensions.json
=====================

该文件夹推荐的扩展，即配置操作时 ``@recommended`` 所搜索到的扩展。

tasks.json
================

该文件夹下能使用的任务，如编译源文件等。

- 其中配置的编译器诊断选项文档见 `Clang 编译器诊断选项列表`_，这些编译选项在实际运行任务时会使用，与 ``compile_commands.json`` 无关。
- 这些诊断选项参考了 `cppbestpractices: Use the Tools Available - compilers`_ 和 `hacking C++: Diagnostic Basics`_。
- 但为便于初学者学习，部分非常严格的诊断未启用；请参照 ``cmake/mine/`` 中的内容，那是我使用的版本。

launch.json
=================
  
该文件夹下能使用调试任务，用于调试。

- 这里预配置的调试任务很多都设置了 ``"preLaunchTask"``，即在启动调试任务之前，执行要求的 ``tasks.json`` 任务。