使用 Homebrew 安装 VSCode 和 LLVM
=================================

继续在【终端】分别输入以下指令、【回车】，等待完成即可。

1. 安装：

  .. code-block:: bash

    brew install llvm ninja

  .. code-block:: bash

    brew install --cask visual-studio-code cmake

  .. code-block:: bash

    pip3 install cmake_format

2. 配置 LLVM 的环境变量（重开【终端】生效）

  .. code-block:: bash

    echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc

  .. code-block:: bash

    echo 'export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"' >> ~/.zshrc

  .. code-block:: bash

    echo 'export CPPFLAGS="-L/opt/homebrew/opt/llvm/lib -Wl,-rpath,/opt/homebrew/opt/llvm/lib"' >> ~/.zshrc

你可以通过【启动台】点击图标启动 VSCode，或按【Command + 空格】打开聚焦搜索，搜索 **code** 以找到。

此后，你可以随时在【终端】输入 `brew upgrade` 更新这些软件。