########
更新日志
########

配置更新方法见 :doc:`how_to_update`。

.. note::

  文档迁移后配置变化颇大，迁移前的配置更新不做记录。

引入语义化版本后
****************

v3.0.4 - 2023-05-04
=====================

- 设置 VSCode 的默认主题，以启用配置的更多色彩的 C++ 代码。

v3.0.3 - 2023-04-29
=====================

- 对于 Windows，换用安装包的方式安装 git，避免 MSYS2 安装 git 可能遇到的问题。

v3.0.2 - 2023-04-27
=====================

- 提示近几天 VSCode CMake Tools 插件更新后，配置时卡住该如何操作。

v3.0.1 - 2023-04-01
=====================

- 补充安装 git。
- 提示 VSCode 未找到齿轮的情况如何操作。
- 提示如何在 M 系列芯片的 MacOS 使用 gcc 时抑制 ``__float128`` 报错。

v3.0.0 - 2023-03-30
=====================

- 更新至 LLVM 16。

v2.1.0 - 2023-03-13
=====================

- 更新 mac 的 homebrew 安装教程，适配 homebrew 4.0。

v2.0.0 - 2023-03-07
=====================

- 使用 VSCode Profile 而非复制粘贴的方式进行配置，这样用户原来安装的扩展不会有影响。

引入语义化版本前
****************

2023-02-05
============

- 设置 CMake 进行并行生成。

2023-02-04
============

- 新增扩展 ``Project Manager``。

2023-01-30
============

- 移除 ``cmake/SymlinkCompileCommands.json``，已将该功能 PR 到 project_options 中。

2023-01-22
============

- 允许 clangd 更热切地索引标准库。

2023-01-19
============

- 更新大量配置：

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

2023-01-18
============

- 强调 ``clangd: Restart language server`` 应当在打开源文件或头文件时进行。

2023-01-16
============

- 开启文件夹时不自动配置 CMake（因为一般已有缓存）。

2023-01-07
============

- 添加“CMake: 编译活动目标”和“Clang-Tidy: 修复当前文件”的 VSCode 任务配置。

2023-01-06
============

- 更改头文件 ``#include`` 的顺序。

2023-01-05
============

- 更新我个人的 MyProjectOptions.cmake，更严格的诊断。
- 为 clangd 启用解析转发函数。
- 为 concepts 着色。

2023-01-03
============

- 在 :doc:`special_announcement` 中新增我个人的 C++ 项目配置模板。
- 更新默认 MyProjectOptions.cmake 设置。
- 加入多彩的注释提示符。
- 更新 settings.json：改善外观，让 CMake “如果已有缓存，则跳过配置环节”。

2022-11-11
============

- 为调试控制台启用自定义字体。

2022-10-15
============

- 扩展 ``CMake Language Support`` 更新，其 ``.json`` 的配置选项命名做了变更，需要更新配置文件。

2022-09-21
============

- 更新至 LLVM 15。

2022-09-11
============

- 将 CMake 源文件管理部分抽象成 ``cmake/StructureOnly.cmake``，从而允许为单源文件代码提供分析的同时管理 CMake 项目，并为未来可能做的 **利用 Conan 添加第三方库** （见 :doc:`todo`）提供接口，目前请通过 :doc:`special_announcement` 自行学习。

2022-09-10
============

- 对 CMake 部分借用 `Github: aminya/project_options`_ 重新配置，更加简洁有效。

2022-09-08
============

- 修正了又一个 Windows 特有问题。见 `Issue: 关于配置异常无输出`_。

2022-09-03
============

- 对配置文件进行了大幅度的调整。
- 用 reStructuredText 重写了文档并进行迁移。

2022-09-10
============

- 在 :doc:`special_announcement` 部分新增一个开源项目 `Github: aminya/project_options`_。

2022-08-27
============

- 更新了 CMake 相关拓展。

2022-08-23
============

- 补充了 Windows 安装 LLVM 的一个操作。

2022-08-20
============

- 在 ``.vscode/launch.json`` 中增加了 CMake 项目用的 LLDB 调试配置，请注意 :doc:`special_announcement`。

2022-08-13
============

- 新增了一个插件 `Error Lens`_，感谢 `【VS Code】四年功力 一刻掌握 速通 C++插件/终端美化/工程管理 懒人必备`_。
- 新增了 :doc:`special_announcement`。

2022-07-08
============

- VSCode 更新了导出/导入配置档案的功能，但涉及的部分自认为足够简单，不想重写，摸了。

2022-06-26
============

- Homebrew 终于更新了 LLVM14（请通过 ``brew upgrade --greedy`` 更新），调整了 MacOS 的配置文件。

2022-06-08
============

- 彻底修复 Windows 调试无法设置断点的问题； **但对于项目仍需自己通过 CMake 进行配置**。见 `Issue: 添加断点无效`_，方法来自 `vscode-lldb: Breakpoints are not getting hit`_。