利用 MSYS2 安装 LLVM
====================


1. 通过【开始】菜单（一般在左下角，Win11 在中间位置），或 **MSYS2 安装路径** （默认为 C:\\msys64 ）找到 **clang64** 或 **clang64.exe**。

  .. note::

    注意是 **clang64** 而非 **msys2**！

2. 【右键】-【以管理员身份运行】。

  .. note::

    注意打开的窗口样式，当输入命令后，再次出现类似样式时，说明命令执行完毕。

    .. figure:: /_img/Clang64_窗口样式.png

       Clang64 窗口样式

3. 在打开的窗口输入以下命令：

  .. note::

    - **一行一行地** 复制（【Control + C】）、粘贴（【窗口内右键 - Paste】而非【Control + V】！如果习惯性按了，先把出现的字符删除）。
    - **多次** 【回车】！ **多次** 【回车】！ **多次** 【回车】！
    - 等待执行完毕后继续下一行。（确定执行完毕的方法见上文。）

  .. code-block:: bash

    pacman -S mingw-w64-clang-x86_64-toolchain mingw-w64-clang-x86_64-cninja mingw-w64-clang-x86_64-python-six mingw-w64-clang-x86_64-python-pip git

  .. code-block:: bash

    pip install cmakelang

  .. code-block:: bash

    pacman -Syu

4. 执行 ``pacman -Syu`` 后，可能需要多次【回车】并重启该软件，关闭并重新打开 **clang64.exe**，再执行一次：

  .. code-block:: bash

    pacman -Syu

此后， 你可以随时在该软件中输入 ``pacman -Syu`` （同上，可能重启）更新这些软件。