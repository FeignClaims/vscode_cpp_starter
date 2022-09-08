可我想要用 gcc
**************

.. include:: /_include/links.rst

请打开 VSCode 设置文件 ``.vscode/settings.json``，找到 ``"clangd.arguments"`` ，在其中插入 ``"--query-driver=你的gcc可执行文件路径"``。

.. figure:: /_img/clangd_with_gcc.png

   配置 gcc

.. note::

  这只是让 clangd 正常解析 gcc 的设置；其余工具链配置可通过 `cmake-toolchains`_ 配置。