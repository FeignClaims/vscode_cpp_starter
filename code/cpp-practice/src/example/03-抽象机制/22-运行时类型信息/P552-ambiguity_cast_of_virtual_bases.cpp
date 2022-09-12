class Storable {
 public:
  virtual ~Storable() = default;
};
class Component : public virtual Storable {};
class Receiver : public Component {};
class Transmitter : public Component {};
class Radio : public Receiver, public Transmitter {};

void h1(Radio& r) {
  Storable* ps{&r};  // 一个 Radio 包含唯一的 Storable
  // ...
  Component* pc{dynamic_cast<Component*>(
      ps)};  //\$ pc == nullptr，因为一个 Radio 包含两个 Component
}

void h2(Storable* ps) {  // ps 可能是一个 Component 指针，也可能不是
  if (Component * pc{dynamic_cast<Component*>(ps)}) {
    // 我们得到了一个 Component！
  } else {
    // ps 不是一个 Component
  }
}