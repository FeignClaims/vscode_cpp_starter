##############
CMake 特别声明
##############

.. include:: /_include/links.rst

提示
*****

本教程并没有创建一个 C++ 项目，只是提供了一个配置好的开发/学习环境；为方便日常学习 C++，内置了运行/调试单个 ``.cpp`` 源代码（必须是这个后缀！）或整个文件夹的便捷脚本。

如果需要配置项目，请自行学习 CMake，并修改根目录下的 ``CMakeLists.txt``。

关于调试，2022 年 8 月 20 日以后，已在配置中给出了调试 CMake 项目的配置。

建议参考 :doc:`bibliography` 给出的文档自行修改配置。

插件相关
********

目前教程给出的配置使用了 ``CMake Tools`` 和 ``CMake Language Support`` 扩展，并启用了打开文件夹或保存 ``CMakeLists.txt`` 时自动配置 CMake。

在设置中，我启用了实验性质的 FileAPI 功能，使得 ``include(xxx)`` 所包含的内容能得到分析， **但该分析仅对上一次配置有效**，即 **修改 ``CMakeLists.txt`` 后，必须重新配置 CMake 才能得到新的分析结果**。

推荐读物
********

- 书籍

  - `《Modern CMake for C++》`_

    - `Modern CMake for C++：代码`_
    - `Modern CMake for C++：ACCU 书评`_

  - `《Professional CMake》`_ **（别用这本书入门！）**

- 视频

  - `Effective CMake - Daniel Pfeife - C++Now 2017`_
  - `Using Modern CMake Patterns to Enforce a Good Modular Design - Mathieu Ropert - CppCon 2017`_
  - `Git, CMake, Conan - How to ship and reuse our C++ projects - Mateusz Pusz - CppCon 2018`_
  - `More Modern CMake - Deniz Bahadir - Meeting C++ 2018`_

- 文档

  - `CMake 官方文档`_
  - `Modern CMake`_
  - `More Modern CMake`_
  - `Effective Modern CMake`_
  - `VSCode CMake 拓展用户手册`_