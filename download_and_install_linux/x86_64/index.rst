************************************************************************************************************************
架构: x86_64
************************************************************************************************************************

========================================================================================================================
安装前置软件
========================================================================================================================

Debian 或 Ubuntu
  .. code-block:: bash

    sudo apt-get install build-essential procps curl file git zip ninja-build libc++-dev libc++abi-dev

Fedora, CentOS 或 Red Hat
  .. code-block:: bash

    sudo yum groupinstall 'Development Tools'
    sudo yum install procps-ng curl file git zip

Arch Linux
  .. code-block:: bash

    sudo pacman -S base-devel procps-ng curl file git zip libc++ libc++abi

.. include:: /linuxbrew.irst