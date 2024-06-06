************************************************************************************************************************
操作系统: Ubuntu/Debian
************************************************************************************************************************

========================================================================================================================
安装软件
========================================================================================================================

在终端运行以下命令以安装所需软件. 如果没有出现上述窗口样式, 请再按一次 :KBD:`回车`.

.. note::

  键入命令后, 如果显示以下内容, 则需要 **输入电脑密码** 并 :KBD:`回车` 以继续!

  .. figure:: 输入电脑密码.png

    输入电脑密码

.. code-block:: bash

  sudo apt remove --purge --auto-remove cmake

.. code-block:: bash

  sudo apt update && sudo apt install -y software-properties-common lsb-release && sudo apt clean all

.. code-block:: bash

  wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null

.. code-block:: bash

  sudo apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"

.. code-block:: bash

  sudo apt update

.. code-block:: bash

  sudo apt install kitware-archive-keyring

.. code-block:: bash

  sudo rm /etc/apt/trusted.gpg.d/kitware.gpg

.. code-block:: bash

  sudo apt update

.. note::

  如果上一行命令后显示以下内容, 请输入 ``sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys <PUBKEY>`` (其中 ``<PUBKEY>`` 是内容中实际显示的 PUBKEY) 并回车.

  .. figure:: CMake_PUBKEY.png

    对应的 PUBKEY 为 ``1A127079A92F09ED``.

.. code-block:: bash

  sudo apt install cmake git ninja-build libstdc++-12-dev

.. code-block:: bash

  sudo bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"

.. code-block:: bash

  install_latest_version() {
    local binary="$1"
    local latest_version=$(ls -1 "/usr/bin/clang"-* 2>/dev/null | grep -oE '[0-9]+' | sort -V | tail -n 1)
    if [ -n "$latest_version" ]; then
      sudo apt install $binary-$latest_version
      echo "Software installed: $binary-$latest_version -> $binary"
    else
      echo "No installed versions of $binary found."
    fi
  }
  install_latest_version "clang-tools"

.. code-block:: bash

  symlink_latest_version() {
    local binary="$1"
    local latest_version=$(ls -1 "/usr/bin/clang"-* 2>/dev/null | grep -oE '[0-9]+' | sort -V | tail -n 1)
    if [ -n "$latest_version" ]; then
        sudo ln -sf "/usr/bin/$binary-$latest_version" "/usr/bin/$binary"
        echo "Symlink created: $binary-$latest_version -> $binary"
    else
        echo "No installed versions of $binary found."
    fi
  }
  symlink_latest_version "clang"
  symlink_latest_version "clang++"
  symlink_latest_version "clang-tidy"
  symlink_latest_version "clang-format"
  symlink_latest_version "clangd"
  symlink_latest_version "lldb"
