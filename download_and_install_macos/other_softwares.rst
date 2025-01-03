************************************************************************************************************************
使用 Homebrew 安装 VSCode 和 LLVM
************************************************************************************************************************

继续在 :menuselection:`终端` 分别输入以下指令, 每次指令输入后都 :KBD:`回车`, 等待完成即可.

安装:

.. code-block:: bash

  brew install llvm ninja git cmake conan ccache dotnet@6

.. code-block:: bash

  brew install --cask visual-studio-code

配置 LLVM 的环境变量 (重开 :menuselection:`终端` 生效):

.. code-block:: bash

  echo "export PATH=\"$(brew --prefix llvm)/bin:\$PATH\"" >> ~/.zshrc

安装完成后, 你可以通过 :menuselection:`启动台` 点击图标启动 VSCode, 或按 :KBD:`Command⌘-空格` 打开聚焦搜索, 搜索 ``code`` 以找到.

此后, 你可以随时在 :menuselection:`终端` 输入 ``brew upgrade --greedy`` 更新这些软件.
