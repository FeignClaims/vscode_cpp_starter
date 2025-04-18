************************************************************************************************************************
利用 MSYS2 安装 LLVM 等软件
************************************************************************************************************************

========================================================================================================================
打开终端
========================================================================================================================

通过 :menuselection:`开始` 菜单 (一般在左下角, Win11 在中间位置), 或 **MSYS2 安装路径** (默认为 ``C:\msys64``) 找到 **clang64.exe** 或 **clang64** (不指 clang64 文件夹, 而是你的电脑上 clang64.exe 可能隐藏了后面的 .exe 后缀名).

.. warning::

  注意是 **clang64** 而非 **msys2**!

:KBD:`右键` 该文件, 选择 :menuselection:`以管理员身份运行`.

.. note::

  注意打开的窗口样式, 当输入命令后再次出现类似样式时, 说明命令执行完毕.

  .. figure:: Clang64_窗口样式.png

    Clang64 窗口样式

========================================================================================================================
进行安装
========================================================================================================================

在打开的窗口输入以下命令：

.. include:: /command_line_hint_others.irst

.. code-block:: bash

  pacman -S mingw-w64-clang-x86_64-toolchain mingw-w64-clang-x86_64-cninja mingw-w64-clang-x86_64-python-six mingw-w64-clang-x86_64-python-pip mingw-w64-clang-x86_64-python-conan mingw-w64-clang-x86_64-ccache git

.. code-block:: bash

  pacman -Syu

执行 ``pacman -Syu`` 后, 可能需要多次 :KBD:`回车` 并重启该软件, 关闭并重新打开 **clang64.exe**, 再执行一次:

.. code-block:: bash

  pacman -Syu

此后, 你可以随时在该软件中输入 ``pacman -Syu`` (同上, 可能重启) 更新这些软件.

========================================================================================================================
验证安装成功
========================================================================================================================

继续打开该软件, 输入以下命令:

.. code-block:: bash

  clangd --version

如果显示 ``clangd: command not found`` 则表示安装出问题, 请重新执行前面的安装命令.

.. tabs::

  .. tab:: 安装成功

    .. figure:: MSYS2_其他软件安装成功.png

  .. tab:: 安装失败

    .. figure:: MSYS2_其他软件安装失败.png