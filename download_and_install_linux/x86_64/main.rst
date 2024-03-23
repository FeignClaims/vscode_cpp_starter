************************************************************************************************************************
架构: x86_64
************************************************************************************************************************

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

  export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"
  export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"
  export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles"
  export HOMEBREW_API_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles/api"

.. code-block:: bash
  :caption: 安装 Linuxbrew

  /bin/bash -c "$(curl -fsSL https://mirrors.ustc.edu.cn/misc/brew-install.sh)"

.. code-block:: bash
  :caption: 配置环境变量

  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.bashrc
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.bash_profile
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.zshrc
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.zprofile
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.profile
  eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"

.. code-block:: bash
  :caption: 配置镜像源

  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.bashrc
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.bashrc
  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.bash_profile
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.bash_profile
  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.zshrc
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.zshrc
  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.zprofile
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.zprofile
  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.profile
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.profile

========================================================================================================================
用 Linuxbrew 安装其他软件
========================================================================================================================

.. code-block:: bash

  brew install llvm cmake ninja git