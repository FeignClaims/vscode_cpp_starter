// STAR: 引用的引用
using rr_i = int&&;
using lr_i = int&;
using rr_rr_i = rr_i&&;  // "int && &&" 的类型是 int&&
using lr_rr_i = rr_i&;   // "int && &" 的类型是 int&
using rr_lr_i = lr_i&&;  // "int & &&" 的类型是 int&
using lr_lr_i = lr_i&;   // "int & &" 的类型是 int&