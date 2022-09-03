########
附加内容
########

可我想要用 gcc
**************

请打开 VSCode 设置文件 ``.vscode/settings.json``，找到 ``"clangd.arguments"`` ，在其中插入 ``"--query-driver=你的gcc可执行文件路径"``。

.. figure:: /_img/clangd_with_gcc.png

   配置 gcc

我的其他 VSCode 通用类拓展
************************

点击下载 `我的通用拓展`_，配置方法与 :doc:`configure` 类似。

此外，建议装上 Vim 插件。

.. _`我的通用拓展`: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/raw/master/code/my_utility.zip

Visual Studio 的配置方案
************************

- `一个简单的 Visual Studio 配置方案`_