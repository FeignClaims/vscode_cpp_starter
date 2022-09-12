class Storable {
 public:
  virtual ~Storable() = default;
};
class Component : public virtual Storable {};
class Receiver : public Component {};
class Transmitter : public Component {};
class Radio : public Receiver, public Transmitter {};

// STAR: dynamic_cast 不能将一个 void* 转换为其他类型
// STAR: static_cast 可以将 void* 转换为其他类型
auto f1(void* p) -> Radio* {
  Storable* ps{static_cast<Storable*>(p)};  //\$ 信任程序员
  return dynamic_cast<Radio*>(ps);
}