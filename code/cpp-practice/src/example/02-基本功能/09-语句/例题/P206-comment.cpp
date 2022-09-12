// tbl.c：实现符号表

/*
  Gaussian elimination with partial pivoting
  见 Ralston: "A first course..."，第 411 页
*/

// scan(p, n, c) 要求 p 指向一个至少包含 n 个元素的数组

// sort(p, q) 用 < 运算符排序序列 [p:q) 中的元素

// 2013-2-29 日修订：处理无效日期。修订者：Bjarne Stroustrup