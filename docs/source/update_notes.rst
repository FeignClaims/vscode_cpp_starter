########
更新日志
########


.. note::

  文档迁移后配置变化颇大，迁移前的配置更新不做记录。

配置更新
********

记录需要更新 `配置文件`_ 的更新，文中所用的 `配置文件`_ 始终保持最新版本。

更新方法见 :doc:`how_to_update`。

- 2023 年 1 月 22 日，允许 clangd 更热切地索引标准库
- 2023 年 1 月 19 日，更新大量配置

  .. code-block:: txt

    根目录
    |
    +-- .clang-format
    +-- .clang-tidy
    +-- .clangd
    +-- .cmake-format.py
    +-- .gitignore
    +-- CMakeLists.txt
    +-- cmake/
    +-- mine/
    +-- .vscode/

- 2023 年 1 月 16 日：开启文件夹时不自动配置 CMake（因为一般已有缓存）。
- 2023 年 1 月 7 日：添加“CMake: 编译活动目标”和“Clang-Tidy: 修复当前文件”的 VSCode 任务配置。
- 2023 年 1 月 6 日：更改头文件 ``#include`` 的顺序。

- 2023 年 1 月 5 日

  - 更新我个人的 MyProjectOptions.cmake，更严格的诊断。
  - 为 clangd 启用解析转发函数。
  - 为 concepts 着色。

- 2023 年 1 月 3 日

  - 更新默认 MyProjectOptions.cmake 设置。
  - 加入多彩的注释提示符。
  - 更新 settings.json：改善外观，让 CMake “如果已有缓存，则跳过配置环节”。

- 2022 年 11 月 11 日，为调试控制台启用自定义字体。
- 2022 年 10 月 15 日，扩展 ``CMake Language Support`` 更新，其 ``.json`` 的配置选项命名做了变更，需要更新配置文件。
- 2022 年 9 月 21 日，更新至 LLVM 15。
- 2022 年 9 月 11 日，将 CMake 源文件管理部分抽象成 ``cmake/StructureOnly.cmake``，从而允许为单源文件代码提供分析的同时管理 CMake 项目，并为未来可能做的 **利用 Conan 添加第三方库** （见 :doc:`todo`）提供接口，目前请通过 :doc:`special_announcement` 自行学习。
- 2022 年 9 月 10 日，对 CMake 部分借用 `Github: aminya/project_options`_ 重新配置，更加简洁有效。
- 2022 年 9 月 8 日，修正了又一个 Windows 特有问题。

  见 `Issue: 关于配置异常无输出`_。

- 2022 年 9 月 3 日，对配置文件进行了大幅度的调整。
- 2022 年 8 月 27 日，更新了 CMake 相关拓展。
- 2022 年 8 月 20 日，在 ``.vscode/launch.json`` 中增加了 CMake 项目用的 LLDB 调试配置，请注意 :doc:`special_announcement`。
- 2022 年 6 月 8 日，彻底修复 Windows 调试无法设置断点的问题； **但对于项目仍需自己通过 CMake 进行配置**。

  见 `Issue: 添加断点无效`_，方法来自 `vscode-lldb: Breakpoints are not getting hit`_。

其他更新
********

- 2023 年 1 月 18 日，强调 ``clangd: Restart language server`` 应当在打开源文件或头文件时进行。
- 2023 年 1 月 3 日，在 :doc:`special_announcement` 中新增我个人的 C++ 项目配置模板。
- 2022 年 9 月 10 日，在 :doc:`special_announcement` 部分新增一个开源项目 `Github: aminya/project_options`_。
- 2022 年 9 月 3 日，用 reStructuredText 重写了文档并进行迁移。
- 2022 年 8 月 23 日，补充了 Windows 安装 LLVM 的一个操作。
- 2022 年 8 月 13 日，新增了 :doc:`special_announcement`。
- 2022 年 8 月 13 日，新增了一个插件 `Error Lens`_，感谢 `【VS Code】四年功力 一刻掌握 速通 C++插件/终端美化/工程管理 懒人必备`_。
- 2022 年 7 月 8 日，VSCode 更新了导出/导入配置档案的功能，但涉及的部分自认为足够简单，不想重写，摸了。
- 2022 年 6 月 26 日，Homebrew 终于更新了 LLVM14（请通过 ``brew upgrade --greedy`` 更新），调整了 MacOS 的配置文件。