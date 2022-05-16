class Storable {
 public:
  virtual ~Storable() = default;
};
class Component : public virtual Storable {};
class Receiver : public Component {};
class Transmitter : public Component {};
class Radio : public Receiver, public Transmitter {};

// STAR: dynamic_cast 可从多态虚基类转换到派生类或兄弟类
// STAR: static_cast 不检查要转换的对象
void g(Radio& r) {
  Receiver* prec{&r};                    // Receiver 是 Radio 的普通基类
  Radio* pr{static_cast<Radio*>(prec)};  //\; 无须检查
  pr = dynamic_cast<Radio*>(prec);       //\; 运行时检查

  Storable* ps{&r};               // Storable 是 Radio 的虚基类
  pr = static_cast<Radio*>(ps);   //\! 不能从虚基类转换
  pr = dynamic_cast<Radio*>(ps);  //\; 运行时检查
}