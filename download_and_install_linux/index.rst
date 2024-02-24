########################################################################################################################
1.下载和安装 (Linux)
########################################################################################################################

.. warning::

  由于 Linux 可能不存在图形界面, 以下内容仅涉及终端软件的安装, 不涉及 VSCode 和字体的安装.

打开 :menuselection:`终端 (Terminal)`, 输入以下内容并 :KBD:`回车` 查看操作系统和架构:

.. warning::

  **一块一块地** 复制 (:KBD:`Control`:KBD:`C`)、粘贴 (:KBD:`窗口内右键` 然后 :menuselection:`Paste` 而非 :KBD:`Control`:KBD:`V`! 如果习惯性按了, 先把出现的字符删除).

.. code-block:: bash
  :caption: 查看操作系统

  uname -n

.. code-block:: bash
  :caption: 查看架构

  uname -m

.. toctree::
  :maxdepth: 1
  :caption: 基于操作系统的教程

  fedora/main.rst
  ubuntu_debian/main.rst

.. toctree::
  :maxdepth: 1
  :caption: 基于架构的教程

  x86_64/main.rst