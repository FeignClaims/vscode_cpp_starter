#include <stdexcept>
template <typename T>
class List {
 public:
  void insert(T);
  auto get() -> T;
  // ...
 private:
  // STAR: 访问控制：成员类型
  struct Link {
    T val;
    Link* next;
  };

  struct Chunk {
    enum { kChunkSize = 15 };
    Link v{kChunkSize};
    Chunk* next;
  };

  auto get_free() -> Link*;

  Chunk* allocated_;
  Link* free_;
  Link* head_;
};

template <typename T>
void List<T>::insert(T val) {
  Link* lnk = get_free();
  lnk->val = val;
  lnk->next = head_;
  head_ = lnk;
}

template <typename T>
auto List<T>::get() -> T {
  if (head_ == 0) {
    throw std::underflow_error{""};
  }

  Link* p = head_;
  head_ = p->next;
  p->next = free_;
  free_ = p;

  return p->val;
}

template <typename T>
auto List<T>::get_free() -> Link* {
  if (free_ == 0) {
    // ... 分配一个新块，将其 Link 放在空闲链表中 ...
  }
  Link* p = free_;
  free_ = free_->next;
  return p;
}