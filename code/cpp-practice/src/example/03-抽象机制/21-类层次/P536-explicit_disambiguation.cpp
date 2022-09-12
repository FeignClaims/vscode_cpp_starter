class Satellite {
 public:
  virtual void get_debug();
};

class Displayed {
 public:
  virtual void get_debug();
};

class CommSat : public Satellite, public Displayed {
 public:
  void get_debug()
      override {  // 覆盖 CommSat::get_debug() 和 Displayed::get_debug()
    Satellite::get_debug();
    Displayed::get_debug();
    // ...
  }
};