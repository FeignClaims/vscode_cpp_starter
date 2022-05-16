#include "P664-conditional.cc"

// STAR: 引入模板别名隐藏 ::type 实现细节，使类型函数更像一个返回类型的函数
template <typename T>
using ObjHolderType = typename ObjHolder<T>::type;