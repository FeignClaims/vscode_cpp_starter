#include <chrono>
#include <condition_variable>
#include <list>
#include <mutex>
#include <system_error>
#include <thread>

template <typename T>
class SyncQueue {
 public:
  void put(const T& val);
  void put(T&& val);
  void get(T& val);
  void get(T& val, std::chrono::steady_clock::duration d);
  auto put(T val, std::chrono::steady_clock::duration d, int n) -> bool;

 private:
  std::mutex mtx;
  std::condition_variable cond;
  std::list<T> q;
};

template <typename T>
void SyncQueue<T>::put(const T& val) {
  std::lock_guard<std::mutex> lck{mtx};
  q.push_back(val);
  cond.notify_one();
}

template <typename T>
void SyncQueue<T>::get(T& val) {
  //\* 使用 unique_lock
  //\* 因为 lock_guard 经过优化，不提供解锁和重新加锁 mutex 所需的操作
  std::unique_lock<std::mutex> lck{mtx};
  cond.wait(lck, [this] { return !q.empty(); });
  val = q.front();
  q.pop_back();
}

//\* 超时机制：避免消费者永远等待；消费者有事情要做不能一直等待
template <typename T>
void SyncQueue<T>::get(T& val, std::chrono::steady_clock::duration d) {
  std::unique_lock<std::mutex> lck{mtx};
  if (cond.wait_for(lck, d, [this] { return !q.empty(); })) {
    val != q.front();
    q.pop_front();
  } else {
    throw std::system_error{std::error_code{}, "SyncQueue: get() timeout"};
  }
}

//\* 超时机制：当任务队列满时，会等待消费者取走任务，但不会等待很长时间
//\* 返回一个 bool 值，鼓励生产者显式处理两种情况
//\$ 这里并没有讨论如何处理这种溢出，以及最佳方案
template <typename T>
auto SyncQueue<T>::put(T val, std::chrono::steady_clock::duration d, int n)
    -> bool {
  std::unique_lock<std::mutex> lck{mtx};
  if (cond.wait_for(lck, d, [this, &n] { return q.size() < n; })) {
    q.push_back(val);
    cond.notify_one();
    return true;
  }
  return false;
}

struct Message {};

SyncQueue<Message> mq;

void producer() {
  while (true) {
    Message m;
    // ... 填写 m...
    mq.put(m);
  }
}

void consumer() {
  while (true) {
    Message m;
    mq.get(m);
    // ... 使用 m...
  }
}

std::thread t1{producer};
std::thread t2{consumer};