#######
5.解释
#######


摸了，以下为一些配置文件的说明，建议从上到下依次阅读。

要想进阶，请参考 :doc:`special_announcement`。

.. code-block:: txt

  根目录
  |
  +-- .clang-format
  +-- .clang-tidy
  +-- .clangd
  +-- compile_commands.json
  +-- CMakeLists.txt
  +-- cmake/
  |   +-- GetProjectOptions.cmake
  |   +-- MyProjectOptions.cmake
  |   +-- StructureOnly.cmake
  |   +-- SymlinkCompileCommands.cmake (已删除, 其功能 PR 已到 project_options 中, 故无需独立添加)
  +-- mine/
  +-- .vscode/
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

它所给出的警告一般会在警告信息最后给出一个蓝色链接，点击会转到一个网页，解释为什么有这个警告以及如何修复。

.. note::

  - 可自动修复的警告：部分 clang-tidy 产生的警告，其警告信息后面会有 ``(fix available)``，则选择它后将会弹出小灯泡样式，点击它可以进行自动修复。
  - 抑制某代码区域警告的方法：如果想要抑制 clang-tidy 产生的警告，则用 ``// NOLINT`` 可以抑制该行警告，用 ``// NOLINTNEXTLINE`` 抑制下一行警告，用 ``// NOLINTBEGIN`` 和 ``// NOLINTEND`` 抑制它们之间的警告。这些都是抑制 clang-tidy 相关所有警告，如果想要抑制一部分，参考官方文档 `Clang-Tidy 抑制诊断的方法`_参考 `Clang-Tidy 抑制诊断的方法`_。

- 此处 clangd 将 ``.clang-tidy`` 和 ``.clangd`` 中的配置文件综合处理。
- 文档见 `Clang-Tidy 诊断选项列表`_。

.clangd
*************

clangd 的配置文件，为程序员提供内联提示、语法高亮等辅助功能，同时内置了 clang-tidy 的功能。

- 文档见 `Clang-Tidy 诊断选项列表`_ 和 `Clangd 官网`_。

compile_commands.json
***************************

该文件在 CMake 进行配置操作后才生成，存储源文件的编译信息，clangd 需要这些信息才能更好地解析代码和理清文件间的关系。

- 根目录下的是该文件的快捷方式，以供 clangd 找到该文件。
- 为减少初学者负担，此处编译信息是假定所有源文件最终编译成一个可执行文件，故编程时 clangd 给出的提示包含整个【cpp_starter】文件夹中的源代码信息；实际影响不大。
- 由于 compile_commands.json 中只是分别存储单个源文件的编译信息，clangd 为了重构能作用于项目，只能假设是源文件来自同一个项目，故而重命名功能可能影响看似不相关的源文件。这主要问题来源于【cpp_starter】为学习之便管理了大量不相干的项目，实际项目中一般会使用名字空间来解决名字重复，影响不大。
- CMake 的学习可参考 :doc:`special_announcement`。

CMakeLists.txt
********************

CMake 的项目配置文件，这里只用来生成 ``compile_commands.json``。

- 为减少初学者负担，此处 CMake 假定所有源文件最终编译成一个可执行文件，故编程时 clangd 给出的提示包含整个【cpp_starter】文件夹中的源代码信息；实际影响不大。
- CMake 的学习可参考 :doc:`special_announcement`。

cmake/
***********

CMake 的分文件和一些脚本文件，分文件会在 ``CMakeLists.txt`` 中用 ``include(文件)`` 包含，相当于 C++ 中的 ``#include``。

考虑到读者的环境和网络条件，与我自用的版本有些差异：

- 所使用的开源项目 `Github: aminya/project_options`_ 已预先下载。
- 代码检查工具、文档生成工具等已禁用；在 ``mine/`` 文件夹下，有我使用的版本。
- CMake 的学习可参考 :doc:`special_announcement`

ProjectOptions.cmake
=============================

获取开源项目 `Github: aminya/project_options`_，考虑到网络条件，已预先下载到 ``project_options`` 文件夹中。

MyProjectOptions.cmake
============================

对 ``project_options`` 进行自定义设置。

- 禁用代码检查工具、文档生成工具等。
- 启用更多的编译器诊断选项，这些选项会被保存到 ``compile_commands.json`` 中，提供给 clangd 进行解析。

StructureOnly.cmake
========================

定义的 CMake 函数，用于将源文件添加到 CMake 中，并与 ``project_options`` 等链接，最终这些信息会保存在 ``compile_commands.json`` 中被 clangd 使用。

.. note::

  这样加入 CMake 中的文件都假定最终编译成一个可执行文件，故一般不能 **通过 CMake** 编译运行，只是提供给 clangd 进行解析。

函数如下所示，其中 ``<xxx>`` 表示必须输入， ``[xxx]`` 表示可选输入。

- ``structure_only([<DIRECTOIRES> <directory>...])``，将文件夹中的文件（以 h hpp hh c cc cxx cpp 结尾）加入 CMake 中。
- ``structure_only_options([<LIBRARIES> <library>...] [<INCLUDES> <include>...])``，通用设置，实际并没有使用。

  - ``LIBRARIES``：structure_only 预链接的库
  - ``INCLUDES``：structure_only 预包含的头文件文件夹

例如，给出的配置将 ``src`` 和 ``test`` 文件夹下的文件加入 CMake 中。

.. code-block:: cmake

  include(StructureOnly)
  structure_only(
    DIRECTORIES
    src
    test
  )

SymlinkCompileCommands.cmake
==================================

.. note::

  该文件已删除，其功能 PR 已到 project_options 中，故无需独立添加。

在包含（ ``include()`` ）该文件的 ``CMakeLists.txt`` 文件所在目录下创建 ``compile_commands.json`` 的快捷方式。

- 创建这个快捷方式便于 clangd 找到 ``compile_commands.json``，兼容源外构建。
- 仅当 CMake 生成器为 Makefiles 或 Ninja 时有效，文中配置已默认设置为 Ninja。（用 ``cmake -S <source> -B <build> -G <generator>`` 来指定， ``cmake --help`` 可查看当前环境可用生成器。）

mine/
***********

我使用的版本，请结合 :doc:`special_announcement` 和 `Github: FeignClaims/cmake_starter_template`_ 学习

需要安装以下软件：

.. code-block:: txt

  conan                 # 包管理工具
  include-what-you-use  # 缩写为 iwyu
  ccache                # 通过缓存加快编译
  doxygen               # 文档生成工具
  cppcheck              # 一个代码检查工具

.vscode/
*****************************
  
该文件夹特定的 VSCode 配置，仅在当前文件夹下有效。

extensions.json
=====================

.. note::

  该文件已不再使用，教程已改为使用 VSCode 的配置文件功能进行。

该文件夹推荐的扩展，即配置操作时 ``@recommended`` 所搜索到的扩展。

tasks.json
================

该文件夹下能使用的任务，如编译源文件等。

- 其中配置的编译器诊断选项文档见 `Clang 编译器诊断选项列表`_，这些编译选项在实际运行任务时会使用，与 ``compile_commands.json`` 无关。
- 这些诊断选项参考了 `cppbestpractices: Use the Tools Available - compilers`_ 和 `hacking C++: Diagnostic Basics`_。
- 但为便于初学者学习，部分非常严格的诊断未启用；请参照 ``mine/`` 中的内容，那是我使用的版本。

launch.json
=================
  
该文件夹下能使用调试任务，用于调试。

- 这里预配置的调试任务很多都设置了 ``"preLaunchTask"``，即在启动调试任务之前，执行要求的 ``tasks.json`` 任务。