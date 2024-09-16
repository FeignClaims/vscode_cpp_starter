************************************************************************************************************************
4.添加你自己的程序
************************************************************************************************************************

你只需要在 ``CMakeLists.txt`` 中用 ``add_program(程序名 源文件1 源文件2...)`` 添加即可.

在 ``src`` 文件夹中我给了两个程序示例, 请对照 ``CMakeLists.txt`` 中是怎么添加它们的:

- ``example_single``: 单个源文件组成的程序.
- ``example_multiple``: 多个源文件组成的程序.

假设 ``src/ex_1.cpp`` 和 ``src/ex_2.cpp`` 分别保存了我们的两个练习:

.. code-block:: cpp
  :linenos:
  :caption: ``src/ex_1.cpp``

  #include <iostream>

  int main() {
    std::cout << "Hello World!\n";
  }

.. code-block:: cpp
  :linenos:
  :caption: ``src/ex_2.cpp``

  #include <print>

  int main() {
    std::println("Hello World!");
  }

它们有自己的 :cpp:`main()` 函数, 显然各自是一个程序, 则我们只需要在 ``CMakeLists.txt`` 文件末尾添加以下内容:

.. code-block:: cmake
  :linenos:

  add_program(ex_1 src/ex_1.cpp)
  add_program(ex_2 src/ex_2.cpp)

这样一来它们就分别添加到我们的项目中, 作为名为 ``ex_1`` 和 ``ex_2`` 的程序.

.. seealso::

  更多请参考 ``请读我`` 文件.