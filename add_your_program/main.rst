************************************************************************************************************************
4.添加你自己的程序
************************************************************************************************************************

========================================================================================================================
程序
========================================================================================================================

所谓程序, 就是我们通过编写代码最终生成的, 可供设备运行的东西. 你所打开的 QQ、微信等都是一个独立的程序.

此处说 "添加你自己的程序", 就是要指明你的程序需要叫什么, 由哪些源文件组成. 为此, 你只需要在 CMakeLists.txt 末尾加上一句 ``add_program(program_name source_file1 source_file2...)``, 就能添加一个名为 ``program_name`` 的程序, 它由 ``source_file1``、 ``source_file2`` **等** (所以有个省略号! 不是说你也要输入这个省略号!) 源文件组成. 这些源代码文件内必须有且仅有一个 ``int main()`` 函数, 它将作为程序执行的入口.

.. warning::

  - program_name、source_file1、source_file2 等等都不要有中文、特殊字符或者空格!
  - program_name 是唯一的, 多个 ``add_program`` 不要重复用同一个 program_name. 最好连 Test、test 这样只是大小写不同的情况都别出现.
  - source_file1、source_file2 等源文件必须实际存在于你的电脑上!

.. note::

  负责管理项目结构的 CMake 会在 CMakeLists.txt 保存时自动重新配置, 而我设置了 VSCode 定时自动保存文件, 所以你在修改 CMakeLists.txt 时可能发现配置失败或右下角弹窗报错. **不要紧张!** 等整个 ``add_program`` 都写好再确定配置是否成功.

  当然, 如果你添加了实际不存在的文件作为源文件, CMake 会配置失败并报错.

这样添加之后, 你就可以像之前 :doc:`/verify/run/main` 和 :doc:`/verify/debug/main` 那样, 选择它、编译生成它、运行它、调试它.

在 CMakeLists.txt 我添加了以下两个示例:

========================================================================================================================
示例: 单个源文件组成的程序
========================================================================================================================

.. code-block:: cmake
  :linenos:

  add_program(example_single
    test/main.cpp
  )

这段代码添加了一个名为 ``example_single`` 的程序, 它由 src/example_single/main.cpp 源代码——src 文件夹里的 example_single 文件夹里的 main.cpp 源文件——组成.

src/example_single/main.cpp 中有一个 :cpp:`int main()` 函数, 它就是该程序执行的入口:

.. code-block:: cpp
  :linenos:
  :caption: src/example_single/main.cpp

  #include "add.hpp"

  #include <iostream>

  int main() {
    std::cout << add(5, 3) << '\n';
  }

由源代码可知, 该程序所做的不过是执行 :cpp:`std::cout << add(5, 3) << '\\n';` 一条语句.

:cpp:`std::cout`
  :cpp:`std::cout` 来自标准库 :cpp:`<iostream>`, 我们通过 :cpp:`#include <iostream>` 来包含 (include) 它.

  一个程序的代码可能不止一个人在写, 可能你写了一个函数命名为 game, 而别的人也写了一个函数命名为 game. 那么, 如何区分这两个函数呢? C++ 由此引入了名字空间的概念. :cpp:`std::cout` 中的 :cpp:`std::` 就是表示使用 std 名字空间——标准库所在的名字空间——中的内容, 所以 :cpp:`std::cout` 就是说使用 std 名字空间中的 cout. 一些教材会在源代码最开始使用 :cpp:`using namespace std;`, 这就是将 std 名字空间中的内容引入到全局名字空间, 进而可以省略 :cpp:`std::`, 直接使用 :cpp:`cout`.

  c 的意思是字符 (character), out 的意思是输出 (output), :cpp:`std::cout` 的意思即输出字符. 而 :cpp:`<<` 就像是管道、箭头一样, 将你要输入的内容从右边流向 :cpp:`std::cout`, 因此常见的 :cpp:`std::cout << "Hello World"` 是将右边的字符串流入到 :cpp:`cout` 中, 即输出 :cpp:`"Hello World"`.

:cpp:`add(5, 3)`
  :cpp:`add(5, 3)` 函数来自于 :cpp:`"add.hpp"`, 我们通过 :cpp:`#include "add.hpp"` 来包含它.

  通过 :KBD:`Ctrl` + :KBD:`鼠标左键` 或 :KBD:`Command⌘` + :KBD:`鼠标左键` :cpp:`#include "add.hpp"` 的文件名 :cpp:`"add.hpp"` 部分, 你可以跳转到对应的文件. 可见, 我们跳转到了 include/add.hpp, 这是我配置的公共头文件存放处, 放在此处的头文件将能被任意位置的源文件直接 :cpp:`#include`.

:cpp:`#include "add.hpp"`
  该文件是头文件 (header file), 相比于源文件 (source file), 它旨在以 :cpp:`#include` 形式被包含到源文件中而被使用, 因此:

  - 它不需要被添加到 ``add_program(<program_name> <source_file1> [source_file2...])`` 中;
  - 为了被正确地 :cpp:`#include`, 它需要编写头文件保护 (见下文).

  打开该文件后, 可以看到以下内容:

  .. code-block:: cpp
    :linenos:
    :caption: include/add.hpp

    #ifndef ADD_HPP
    #define ADD_HPP

    inline int add(int lhs, int rhs) {
      return lhs + rhs;
    }

    #endif

  其中, 开头的 :cpp:`#ifndef` 和 :cpp:`#define`, 以及末尾的 :cpp:`#endif` 行被称为头文件保护 (include guard). 头文件往往需要添加头文件保护从而避免重复地添加同一头文件.

  更多内容请阅读 ``请读我`` 文件和你的教材.

:cpp:`'\\n'`
  这是换行字符 (newline). 一些教材中会用 :cpp:`std::endl` (endline) 表示换行, 但实际进行了多余操作, 具体请参考 :ref:`换行符号 <question_board:newline_character>` 和你的教材 (? 真的会讲吗).

========================================================================================================================
示例: 多个源文件组成的程序
========================================================================================================================

.. code-block:: cmake
  :linenos:

  add_program(example_multiple
    src/example_multiple/main.cpp
    src/example_multiple/hello.cpp
  )

这段代码添加了一个名为 ``example_multiple`` 的程序, 它由 src/example_multiple/main.cpp 和 src/example_multiple/hello.cpp 中.


.. code-block:: cpp
  :linenos:
  :caption: src/example_multiple/main.cpp

  #include "hello.hpp"

  int main() {
    hello();
  }

由源代码可知, 该程序的执行无非是以 :cpp:`int main()` 函数为入口, 调用 :cpp:`hello()` 函数.

为什么 src/example_multiple/main.cpp 会知道有个 :cpp:`hello()` 函数呢? 因为 :cpp:`#include "hello.hpp"` 所包含的头文件中书写了该函数的声明, 但是可以注意到的是, **该头文件中并没有定义 hello() 函数要干什么**.

.. code-block:: cpp
  :linenos:
  :caption: src/example_multiple/hello.hpp

  #ifndef HELLO_HPP
  #define HELLO_HPP

  void hello();  // 这是 hello 函数, 但是它具体做什么?

  #endif

我们的程序是多个源文件的, 另一个源文件 src/example_multiple/hello.cpp 即定义了 :cpp:`hello()` 函数:

.. code-block:: cpp
  :linenos:
  :caption: src/example_multiple/hello.cpp

  #include "hello.hpp"

  #include <iostream>

  void hello() {
    std::cout << "hello world!\n";
  }

由此, 该程序的执行就是以 :cpp:`int main()` 函数为入口, 调用 :cpp:`hello()` 函数, 该函数将会输出 :cpp:`"hello world!\\n"`.

回过头来看我们的 ``add_program``:

.. code-block:: cmake
  :linenos:

  add_program(example_multiple
    src/example_multiple/main.cpp   # 定义程序入口函数 main, 它调用 hello 函数.
    src/example_multiple/hello.cpp  # 定义 hello 函数
  )

那么, 如果我们再写一个源文件 hello2.cpp, 它将 :cpp:`hello()` 函数定义为输出 :cpp:`"hello c++!\\n"` 呢?

.. code-block:: cpp
  :linenos:

  #include "hello.hpp"

  #include <iostream>

  void hello() {
    std::cout << "hello c++!\n";
  }

我们自然可以用它和 ``main.cpp`` 再组成一个程序:

.. code-block:: cmake
  :linenos:

  add_program(example_multiple
    src/example_multiple/main.cpp   # 定义程序入口函数 main, 它调用 hello 函数.
    src/example_multiple/hello.cpp  # 定义 hello 函数
  )
  add_program(example_multiple2
    src/example_multiple/main.cpp    # 同样用 main.cpp
    src/example_multiple/hello2.cpp  # 用另一种方式定义 hello 函数
  )

这两个程序复用同一个 ``main.cpp``, 而输出不同的结果.

.. seealso::

  与学习模板相关的更多内容请参考请参考 :doc:`appendix/explain` 和学习模板内的 ``请读我`` 文件.
