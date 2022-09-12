class Date {
 public:
  explicit Date(int dd = 0, int mm = 0, int yy = 0);

 private:
  int d;
  int m;
  int y;
};

void my_fct(Date d);

Date d1{15};         // 正确：被看作显式类型转换
Date d2 = Date{15};  // 正确：显式类型转换
Date d3 = {15};      //\! = 方式的初始化不能进行隐式类型转换
Date d4 = 15;        //\! = 方式的初始化不能进行隐式类型转换

void f() {
  my_fct(15);        //\! 参数传递不能进行隐式类型转换
  my_fct({15});      //\! 参数传递不能进行隐式类型转换
  my_fct(Date{15});  // 正确：显式类型转换
}