#include <pthread.h>
#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>

void worker(std::promise<void>* p) {
  std::this_thread::sleep_for(std::chrono::seconds(10));
  p->set_value();
}

int main() {
  // void 의 경우 어떠한 객체도 전달하지 않지만, future 가 set 이 되었냐
  // 안되었느냐의 유무로 플래그의 역할을 수행할 수 있다
  std::promise<void> p;
  
  std::future<void> data = p.get_future();
  
  std::thread t(worker, &p);
  
  while (true) {
    std::future_status status = data.wait_for(std::chrono::seconds(1));
    
    // 아직 준비가 안됨
    if (status == std::future_status::timeout) {
      // 에러의 출력은 std::cerr, 로그의 출력은 std::clog
      std::cerr << ">";
    // promise 가 future 을 설정함
    } else if (status == std::future_status::ready) {
      break;
    }
  }
  t.join();
}