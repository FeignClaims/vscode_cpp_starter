#include <string>

struct Storable {  // 持久存储
  virtual ~Storable() = default;

  virtual auto get_file() -> std::string = 0;
  virtual void read() = 0;
  virtual void write() = 0;
};

class Transmitter : public Storable {
 public:
  void write() override;
  // ...
};

class Receiver : public Storable {
 public:
  void write() override;
};

class Radio : public Transmitter, public Receiver {
 public:
  auto get_file() -> std::string override;
  void read() override;
  void write() override;
};

void Radio::write() {
  Transmitter::write();
  Receiver::write();
  // ... 写入 radio 特定的信息 ...
}