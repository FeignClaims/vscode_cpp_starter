class Date {};

class LvalBox {
 public:
  virtual ~LvalBox() = default;
};

void g(LvalBox* pb, Date* pd) {
  void* pb1{dynamic_cast<void*>(pb)};
  void* pb2{dynamic_cast<void*>(pd)};  //\! 不是多态类型
}