// 프로그램의 진행이 여러 갈래로 갈라져서 동시에 진행되는 것을
// 비동기적(asynchronous) 실행이라고 한다
#include <pthread.h>
#include <future>
#include <iostream>
#include <string>
#include <thread>
using std::string;

void worker(std::promise<string>* p) {
  p->set_value("some data");
}

int main() {
  std::promise<string> p;
  
  // 미래에 string 데이터를 돌려 주겠다는 약속
  // promise 는 producer, future 은 consumer
  std::future<string> data = p.get_future();
  
  std::thread t(worker, &p);
  
  // 미래에 약속된 데이터를 받을 때까지 기다린다
  data.wait();
  
  // wait 가 리턴했다는 뜻이 future 에 데이터가 준비되었다는 의미
  // wait 없이 그냥 get 해도 wait 한 것과 같다
  std::cout << "받은 데이터 : " << data.get() << std::endl;
  
  t.join();
}