************************************************************************************************************************
安装 Linuxbrew 和其他软件
************************************************************************************************************************

========================================================================================================================
打开 WSL 终端
========================================================================================================================

安装完成后, 会自动弹出一个 WSL 终端. 你也可以通过 :KBD:`Win`:KBD:`R` 打开 **运行**, 填入 ``ubuntu`` 并 :KBD:`回车` 来启动终端.

.. note::

  注意打开的窗口样式, 当输入命令后再次出现类似样式时, 说明命令执行完毕.

  .. figure:: WSL_窗口样式.png

    WSL 窗口样式

.. note::

  键入命令后, 如果显示以下内容, 则需要 **输入刚刚设置的密码** 并 :KBD:`回车` 以继续!

  .. figure:: WSL_输入密码.png

    输入用户密码

========================================================================================================================
安装系统必须软件
========================================================================================================================

------------------------------------------------------------------------------------------------------------------------
配置镜像源
------------------------------------------------------------------------------------------------------------------------

.. warning::

  - **一块一块地** 复制 (点击代码右上角按钮)、粘贴 (:KBD:`窗口内右键`! 如果习惯性按了 :KBD:`Ctrl`:KBD:`V`, 狂按几次 :KBD:`删除键`).
  - **多次** :KBD:`回车`! **多次** :KBD:`回车`! **多次** :KBD:`回车`!
  - 等待执行完毕后继续下一行. (确定执行完毕的方法见上文.)
  - 如果实在卡住太长时间, :KBD:`Ctrl`:KBD:`C` 终止执行, 重新输入并执行命令.

.. code-block:: bash

  sudo sed -i 's@//.*archive.ubuntu.com@//mirrors.ustc.edu.cn@g' /etc/apt/sources.list

------------------------------------------------------------------------------------------------------------------------
安装
------------------------------------------------------------------------------------------------------------------------

.. code-block:: bash

  sudo apt update

.. code-block:: bash

  sudo apt install build-essential procps curl file git

========================================================================================================================
安装 Linuxbrew
========================================================================================================================

------------------------------------------------------------------------------------------------------------------------
配置镜像源
------------------------------------------------------------------------------------------------------------------------

.. code-block:: bash

  export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"
  export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"
  export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles"
  export HOMEBREW_API_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles/api"
  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.bashrc
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.bashrc
  echo 'export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles"' >> ~/.bashrc
  echo 'export HOMEBREW_API_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles/api"' >> ~/.bashrc
  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.bash_profile
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.bash_profile
  echo 'export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles"' >> ~/.bash_profile
  echo 'export HOMEBREW_API_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles/api"' >> ~/.bash_profile
  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.zshrc
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.zshrc
  echo 'export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles"' >> ~/.zshrc
  echo 'export HOMEBREW_API_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles/api"' >> ~/.zshrc
  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.zprofile
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.zprofile
  echo 'export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles"' >> ~/.zprofile
  echo 'export HOMEBREW_API_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles/api"' >> ~/.zprofile
  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.profile
  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.profile
  echo 'export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles"' >> ~/.profile
  echo 'export HOMEBREW_API_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles/api"' >> ~/.profile

------------------------------------------------------------------------------------------------------------------------
安装
------------------------------------------------------------------------------------------------------------------------

.. code-block:: bash

  /bin/bash -c "$(curl -fsSL https://mirrors.ustc.edu.cn/misc/brew-install.sh)"

------------------------------------------------------------------------------------------------------------------------
设置环境变量
------------------------------------------------------------------------------------------------------------------------

.. code-block:: bash

  eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.bashrc
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.bash_profile
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.zshrc
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.zprofile
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.profile

========================================================================================================================
使用 Linuxbrew 安装其他软件
========================================================================================================================

.. code-block:: bash

  brew install llvm cmake ninja git