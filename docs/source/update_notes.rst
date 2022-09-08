########
更新日志
########

.. include:: /_include/links.rst

配置更新
********

记录需要更新 `配置文件`_ 的更新，文中所用的 `配置文件`_ 始终保持最新版本。

.. note::

  由于配置文件没多少，想更新配置文件请直接重新下载 `配置文件`_ 进行操作。

- 2022 年 9 月 8 日，修正了又一个 Windows 特有问题。

  见 `Issue: 关于配置异常无输出`_。

- 2022 年 9 月 3 日，对配置文件进行了大幅度的调整。
- 2022 年 8 月 27 日，更新了 CMake 相关拓展。
- 2022 年 8 月 20 日，在 ``.vscode/launch.json`` 中增加了 CMake 项目用的 LLDB 调试配置，请注意 :doc:`special_announcement`。
- 2022 年 6 月 8 日，彻底修复 Windows 调试无法设置断点的问题；**但对于项目仍需自己通过 CMake 进行配置**。

  见 `Issue: 添加断点无效`_，方法来自 `vscode-lldb: Breakpoints are not getting hit`_。

其他更新
********

- 2022 年 9 月 3 日，用 reStructuredText 重写了文档并进行迁移。
- 2022 年 8 月 23 日，补充了 Windows 安装 LLVM 的一个操作。
- 2022 年 8 月 13 日，新增了 :doc:`special_announcement`。
- 2022 年 8 月 13 日，新增了一个插件 `Error Lens`_，感谢 `【VS Code】四年功力 一刻掌握 速通 C++插件/终端美化/工程管理 懒人必备`_。
- 2022 年 7 月 8 日，VSCode 更新了导出/导入配置档案的功能，但涉及的部分自认为足够简单，不想重写，摸了。
- 2022 年 6 月 26 日，Homebrew 终于更新了 LLVM14（请通过 ``brew upgrade`` 更新），调整了 MacOS 的配置文件。