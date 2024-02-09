************************************************************************************************************************
附0.关于 CMake 及项目管理的声明
************************************************************************************************************************

========================================================================================================================
提示
========================================================================================================================

本教程虽然使用 CMake 创建了一个学习用文件夹, 但只是为了提供一个配置好的开发/学习环境, 并不适合复杂的项目.

如果需要配置项目, 请自行学习 CMake, 并修改根目录下的 ``CMakeLists.txt``.

此外, 建议参考 :doc:`/bibliography` 给出的文档自行修改配置.

========================================================================================================================
插件相关
========================================================================================================================

目前教程给出的配置使用了 ``CMake Tools`` 和 ``CMake Language Support`` 扩展.

在设置中, 我启用了实验性质的 FileAPI 功能, 使得 ``include(xxx)`` 所包含的内容能得到分析, **但该分析仅对上一次配置有效**, 即 **修改 CMakeLists.txt 后, 必须重新配置 CMake 才能得到新的分析结果**.

========================================================================================================================
建议学习路线
========================================================================================================================

从上到下

- `《Modern CMake for C++》`_
- `Github: aminya/project_options`_
- `Effective CMake - Daniel Pfeife - C++Now 2017`_
- 私货, CMake + Conan

  - `Git, CMake, Conan - How to ship and reuse our C++ projects - Mateusz Pusz - CppCon 2018`_
  - `Github: FeignClaims/cmake_starter_template`_
- `CMake 2022 C++ Modules and More - Bill Hoffman - CppNow 2022`_

========================================================================================================================
推荐读物
========================================================================================================================

- 书籍

  - `《Modern CMake for C++》`_

    - `Modern CMake for C++: 代码`_
    - `Modern CMake for C++: ACCU 书评`_

  - `《Professional CMake》`_ **（别用这本书入门！）**

- 开源项目

  - `Github: aminya/project_options`_
  
    - 大幅简化 CMake 项目的基本构建流程, 几步即可达到《Modern CMake for C++》最终效果, 建议看完后尝试配置.
    
    - 本教程的配置方案已借用这个项目来搭建, 以供 CMake 学习参考.
  
  - `Github: FeignClaims/cmake_starter_template`_

    - 我基于 ``aminya/project_options`` 的 C++ 项目配置模板, 使用 Conan 2.0 进行包管理.

- 视频

  - `Effective CMake - Daniel Pfeife - C++Now 2017`_
  - `Using Modern CMake Patterns to Enforce a Good Modular Design - Mathieu Ropert - CppCon 2017`_
  - `Git, CMake, Conan - How to ship and reuse our C++ projects - Mateusz Pusz - CppCon 2018`_
  - `More Modern CMake - Deniz Bahadir - Meeting C++ 2018`_
  - `Deep CMake for Library Authors - Craig Scott - CppCon 2019`_
  - `Oh No! More Modern CMake - Deniz Bahadir - Meeting C++ 2019`_
  - `CMake 2022 C++ Modules and More - Bill Hoffman - CppNow 2022`_
  - `import CMake - 2023 State of C++20 modules in CMake - Bill Hoffman - CppNow 2023`_

- 文档/文章

  - `CMake 官方文档`_
  - `Modern CMake`_
  - `More Modern CMake`_
  - `Effective Modern CMake`_
  - `VSCode CMake 拓展用户手册`_
  - `preferred cmake project structure`_