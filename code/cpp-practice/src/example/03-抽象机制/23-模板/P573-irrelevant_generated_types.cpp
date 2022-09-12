#include <vector>

class Shape {};
class Circle : public Shape {};

// STAR: 模板用相关实参生成的类型不一定是相关的
Shape* p{new Circle()};                            // Circle* 转换为 Shape*
std::vector<Shape>* a{new std::vector<Circle>{}};  //\! std::vector<Circle>*
    //\! 不能转换为 std::vector<Shape>*

std::vector<Shape> b{std::vector<Circle>{}};  //\! std::vector<Circle>
    //\! 不能转换为 std::vector<Shape>
std::vector<Shape*> c{std::vector<Circle*>{}};  //\! std::vector<Circle*>
    //\! 不能转换为 std::vector<Shape*>