
.. _`Visual Studio 附录`:

************************************************************************************************************************
附录
************************************************************************************************************************

========================================================================================================================
MSVC 的命令行选项
========================================================================================================================

MSVC (即 Visual Studio 系列, 不包括 VS Code) 推荐的错误检查选项 (摘自 `cppbestpractices: Use the Tools Available - compilers - MSVC <https://github.com/cpp-best-practices/cppbestpractices/blob/master/02-Use_the_Tools_Available.md#msvc>`_):

- 你应该默认启用的: ``/permissive- /W4 /w14640``
- 根据需要添加

  - ``/permissive-`` Enforces standards conformance.
  - ``/W4`` All reasonable warnings
  - ``/w14242`` 'identfier': conversion from 'type1' to 'type1', possible loss of data
  - ``/w14254`` 'operator': conversion from 'type1:field_bits' to 'type2:field_bits', possible loss of data
  - ``/w14263`` 'function': member function does not override any base class virtual member function
  - ``/w14265`` 'classname': class has virtual functions, but destructor is not virtual instances of this class may not be destructed correctly
  - ``/w14287`` 'operator': unsigned/negative constant mismatch
  - ``/we4289`` nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside the for-loop scope
  - ``/w14296`` 'operator': expression is always 'boolean_value'
  - ``/w14311`` 'variable': pointer truncation from 'type1' to 'type2'
  - ``/w14545`` expression before comma evaluates to a function which is missing an argument list
  - ``/w14546`` function call before comma missing argument list
  - ``/w14547`` 'operator': operator before comma has no effect; expected operator with side-effect
  - ``/w14549`` 'operator': operator before comma has no effect; did you intend 'operator'?
  - ``/w14555`` expression has no effect; expected expression with side-effect
  - ``/w14619`` pragma warning: there is no warning number 'number'
  - ``/w14640`` Enable warning on thread un-safe static member initialization
  - ``/w14826`` Conversion from 'type1' to 'type_2' is sign-extended. This may cause unexpected runtime behavior.
  - ``/w14905`` wide string literal cast to 'LPSTR'
  - ``/w14906`` string literal cast to 'LPWSTR'
  - ``/w14928`` illegal copy-initialization; more than one user-defined conversion has been implicitly applied