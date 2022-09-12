#include <string>
#include <vector>

std::vector<std::string> v1{77};  // 77 个元素初始化为默认值 ""
    // (vector<string>(initializer_list<string>) 不接受 {77})
std::vector<std::string> v2(77);  // 77 初始化为默认值 ""

std::vector<std::string> v3{"Booh!"};  // 一个元素初始化为 "Booh!"
std::vector<std::string> v4("Booh!");  //\! 没有构造函数接受单一字符串参数

std::vector<int*> v5{100,
                     0};  // 100 个 int* 初始化为 nullptr(100 不是一个 int*)
std::vector<int*> v6{0, 0};  // 2个 int* 初始化为 nullptr
std::vector<int*> v7(0, 0);  // 空 vector(v7.size() == 0)
std::vector<int*> v8;        // 空 vector(v8.size() == 0)