class Representation {};
class Descriptor {};

class Image {
 public:
  Image(const Image& a);

  void write_block(Descriptor);

 private:
  auto clone() -> Representation*;  // 拷贝 *rep

  Representation* rep_;
  bool shared_;
};

// 进行浅拷贝并准备进行写前拷贝
Image::Image(const Image& a) : rep_{a.rep_}, shared_{true} {
}

void Image::write_block(Descriptor d) {
  // STAR: 写前拷贝：有效地结合真拷贝的简单性和浅拷贝的性能
  if (shared_) {
    rep_ = clone();   // 拷贝 *rep
    shared_ = false;  // 不再共享
  }
  // ... 现在我们可以安全地修改我们自己的 rep 副本 ...
}