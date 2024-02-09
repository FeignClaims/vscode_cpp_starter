************************************************************************************************************************
安装 Homebrew
************************************************************************************************************************

.. note::

  参照自 `中科大源: 使用科大源安装 homebrew / linuxbrew`_.

========================================================================================================================
打开终端
========================================================================================================================

:KBD:`Command`:KBD:`空格` 打开聚焦搜索, 搜索 **终端** 并打开.

.. note::

  注意此时的窗口样式, 当输入命令后再次出现类似样式时, 说明命令执行完毕:

  .. figure:: /_img/MacOS终端_窗口样式.png

      终端窗口样式

========================================================================================================================
安装 XCode
========================================================================================================================

输入 ``xcode-select --install`` 并 :KBD:`回车`, 在弹出的页面中点击 :menuselection:`安装`, 再点击 :menuselection:`同意`, 等待安装完成.

.. figure:: /_img/MacOS_安装xcode-select.png

    安装 xcode-select

========================================================================================================================
设置 Homebrew/Linuxbrew 安装镜像
========================================================================================================================

在终端输入以下命令设置安装镜像:

.. warning::

  - **一行一行地** 复制 (:KBD:`Control`:KBD:`C`)、粘贴 (:KBD:`窗口内右键` 然后 :menuselection:`Paste` 而非 :KBD:`Control`:KBD:`V`! 如果习惯性按了, 先把出现的字符删除).
  - **多次** :KBD:`回车`! **多次** :KBD:`回车`! **多次** :KBD:`回车`!
  - 等待执行完毕后继续下一行. (确定执行完毕的方法见上文.)

.. code-block:: bash

  export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"

.. code-block:: bash

  export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"

.. code-block:: bash

  export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles"

.. code-block:: bash

  export HOMEBREW_API_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles/api"

========================================================================================================================
安装 Homebrew/Linuxbrew
========================================================================================================================
  
在终端运行以下命令以安装 Homebrew/Linuxbrew.

.. code-block:: bash

  /bin/bash -c "$(curl -fsSL https://mirrors.ustc.edu.cn/misc/brew-install.sh)"

.. note::

  键入这一行命令后, 需要 **输入电脑密码** 并 :KBD:`回车`、再 :KBD:`回车` 以继续!

  .. figure:: /_img/MacOS_输入电脑密码.png

    输入电脑密码

.. _设置 homebrew/Linuxbrew 环境变量:

========================================================================================================================
设置 Homebrew/Linuxbrew 环境变量
========================================================================================================================

输入 ``uname -m`` 并 :KBD:`回车`, 如果输出 ``arm64`` 则需要添加环境变量, 否则跳过这一部分.

将 brew 程序的相关路径加入到环境变量中.

.. code-block:: bash

  echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.bash_profile

.. code-block:: bash

  echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile

.. code-block:: bash

  eval "$(/opt/homebrew/bin/brew shellenv)"

.. note::

  更泛用的方式是 Homebrew/Linuxbrew 安装完成后, 查看 :menuselection:`终端` 提示的 `Next steps` 并逐步进行.
  
  .. figure:: /_img/MacOS_Next_steps.png

    Next Steps

========================================================================================================================
配置下载镜像源
========================================================================================================================

.. note::

  如果按照 :ref:`设置 homebrew/Linuxbrew 环境变量` 备注中的 `Next steps` 操作了, 跳过这一步.

.. code-block:: bash

  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.bash_profile

.. code-block:: bash

  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.bash_profile

.. code-block:: bash

  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.profile

.. code-block:: bash

  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.profile

.. code-block:: bash

  echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.zprofile

.. code-block:: bash

  echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.zprofile