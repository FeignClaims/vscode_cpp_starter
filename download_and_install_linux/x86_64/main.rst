************************************************************************************************************************
架构: x86_64
************************************************************************************************************************

========================================================================================================================
打开终端
========================================================================================================================

由于差异太大, 请自行搜索如何打开终端.

.. note::

  注意终端的窗口样式, 当输入命令后再次出现类似样式时, 说明命令执行完毕:

  .. figure:: 窗口样式.png

    终端窗口样式

========================================================================================================================
安装前置软件
========================================================================================================================

Debian 或 Ubuntu
  .. code-block:: bash

    sudo apt-get install build-essential procps curl file git

Fedora, CentOS 或 Red Hat
  .. code-block:: bash

    sudo yum groupinstall 'Development Tools'
    sudo yum install procps-ng curl file git

Arch Linux
  .. code-block:: bash

    sudo pacman -S base-devel procps-ng curl file git

========================================================================================================================
安装 Linuxbrew
========================================================================================================================

在终端运行以下命令以安装所需软件. 如果没有出现上述窗口样式, 请再按一次 :KBD:`回车`.

.. note::

  键入命令后, 如果显示以下内容, 则需要 **输入电脑密码** 并 :KBD:`回车` 以继续!

  .. figure:: 输入电脑密码.png

    输入电脑密码

.. code-block:: bash
  :caption: 配置安装镜像源

  export HOMEBREW_API_DOMAIN="https://mirrors.tuna.tsinghua.edu.cn/homebrew-bottles/api"
  export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.tuna.tsinghua.edu.cn/homebrew-bottles"
  export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/brew.git"
  export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/homebrew-core.git"

.. code-block:: bash
  :caption: 安装 Linuxbrew

  /bin/bash -c "$(curl -fsSL https://mirrors.ustc.edu.cn/misc/brew-install.sh)"

.. code-block:: bash
  :caption: 配置环境变量

  test -d ~/.linuxbrew && eval "$(~/.linuxbrew/bin/brew shellenv)"
  test -d /home/linuxbrew/.linuxbrew && eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"
  test -r ~/.bash_profile && echo "eval \"\$($(brew --prefix)/bin/brew shellenv)\"" >> ~/.bash_profile
  test -r ~/.profile && echo "eval \"\$($(brew --prefix)/bin/brew shellenv)\"" >> ~/.profile
  test -r ~/.zprofile && echo "eval \"\$($(brew --prefix)/bin/brew shellenv)\"" >> ~/.zprofile

.. code-block:: bash
  :caption: 配置镜像源

  test -r ~/.bash_profile && echo 'export HOMEBREW_API_DOMAIN="https://mirrors.tuna.tsinghua.edu.cn/homebrew-bottles/api"' >> ~/.bash_profile  # bash
  test -r ~/.bash_profile && echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/brew.git"' >> ~/.bash_profile  # bash
  test -r ~/.bash_profile && echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/homebrew-core.git"' >> ~/.bash_profile
  test -r ~/.profile && echo 'export HOMEBREW_API_DOMAIN="https://mirrors.tuna.tsinghua.edu.cn/homebrew-bottles/api"' >> ~/.profile
  test -r ~/.profile && echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/brew.git"' >> ~/.profile
  test -r ~/.profile && echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/homebrew-core.git"' >> ~/.profile

  test -r ~/.zprofile && echo 'export HOMEBREW_API_DOMAIN="https://mirrors.tuna.tsinghua.edu.cn/homebrew-bottles/api"' >> ~/.zprofile  # zsh
  test -r ~/.zprofile && echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/brew.git"' >> ~/.zprofile  # zsh
  test -r ~/.zprofile && echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/homebrew-core.git"' >> ~/.zprofile

========================================================================================================================
用 Linuxbrew 安装其他软件
========================================================================================================================

.. code-block:: bash

  brew install llvm cmake ninja git