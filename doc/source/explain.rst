#####
解释
#####

.. include:: /_include/links.rst

摸了，以下为一些配置文件的说明。

- ``.clang-format``

  - 代码自动格式化的配置文件。
  - 文档见 `Clang-Format 配置选项列表`_。

- ``.clangd``

  - clangd 的配置文件。
  - 文档见 `Clang-Tidy 诊断选项列表`_ 和 `Clangd 官网`_。

- ``compile_commands.json``

  - 进行配置后才生成，存储源文件的编译信息，clangd 需要这些信息才能更好地解析代码。
  - 根目录下的是该文件的快捷方式，以供 clangd 找到该文件。

- ``CMakeLists.txt``

  - CMake 的项目配置文件，这里只用来生成 ``compile_commands.json``。
  - CMake 的学习可参考 :doc:`special_announcement`。

- ``cmake/SymlinkCompileCommands.cmake``

  - ``CMakeLists.txt`` 的分文件，在 ``CMakeLists.txt`` 开头被包含。
  - 指示 CMake 配置时生成 ``compile_commands.json``，并在包含该文件的 ``CMakeLists.txt`` 文件目录下创建 ``compile_commands.json`` 的快捷方式。

- ``.vscode/extensions.json``
  
  - 该文件夹推荐的扩展，即配置操作时 ``@recommended`` 所搜索到的扩展。

- ``.vscode/tasks.json``

  - 该文件夹下能使用的任务，如编译源文件等。
  - 其中配置的编译器诊断选项文档见 `Clang 编译器诊断选项列表`_。

- ``.vscode/launch.json``
  
  - 该文件夹下能使用调试任务，用于调试。
  - 这里预配置的调试任务很多都设置了 ``"preLaunchTask"``，即在启动调试任务之前，执行要求的 ``tasks.json`` 任务。