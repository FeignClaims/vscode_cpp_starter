########################################################################################################################
1.下载和安装 (Linux)
########################################################################################################################

.. warning::

  由于 Linux 可能不存在图形界面, 以下内容仅涉及终端软件的安装, 不涉及 VSCode 和字体的安装.

************************************************************************************************************************
打开终端
************************************************************************************************************************

由于差异太大, 请自行搜索如何打开终端.

.. note::

  注意终端的窗口样式, 当输入命令后再次出现类似样式时, 说明命令执行完毕:

  .. figure:: 窗口样式.png

    终端窗口样式

************************************************************************************************************************
查看操作系统和架构
************************************************************************************************************************

打开 :menuselection:`终端 (Terminal)` 后, 输入以下内容并 :KBD:`回车` 查看操作系统和架构:

.. warning::

  - **一块一块地** 复制 (点击代码右上角按钮)、粘贴 (:KBD:`窗口内右键` 然后 :menuselection:`Paste` 而非 :KBD:`Control` + :KBD:`V`! 如果习惯性按了, 狂按几次 :KBD:`删除键`).
  - **多次** :KBD:`回车`! **多次** :KBD:`回车`! **多次** :KBD:`回车`!
  - 等待执行完毕后继续下一行. (确定执行完毕的方法见上文.)
  - 如果实在卡住太长时间, :KBD:`Ctrl` + :KBD:`C` 终止执行, 重新输入并执行命令.

.. code-block:: bash
  :caption: 查看操作系统

  uname -n

.. code-block:: bash
  :caption: 查看架构

  uname -m

************************************************************************************************************************
选择合适的教程
************************************************************************************************************************

.. toctree::
  :maxdepth: 1
  :caption: 基于操作系统的教程

  fedora/main.rst
  ubuntu_debian/main.rst

.. toctree::
  :maxdepth: 1
  :caption: 基于架构的教程

  x86_64/main.rst