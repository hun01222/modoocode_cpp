#include <pthread.h>
#include <future>
#include <iostream>
#include <thread>

int some_task(int x) { return 10 + x; }

// promise-future 패턴을 Callable 함수의 리턴값에
// 간단히 적용할 수 있는 packaged_task 를 지원

int main() {
  // int(int) : int 를 리턴하고 인자로 int 를 받는 함수
  // std::function 은 함수 포인터를 대체한다.
  std::packaged_task<int(int)> task(some_task);
  
  std::future<int> start = task.get_future();
  
  // packaged_task 와 promise 는 복사 생성이 불가능하므로
  // 명시적으로 move 해줘야 한다
  // move 는 우측값 레퍼런스 타입으로 static_cast 하는 것과 동일하다
  std::thread t(std::move(task), 5);
  
  std::cout << "결과값 : " << start.get() << std::endl;
  t.join();
}