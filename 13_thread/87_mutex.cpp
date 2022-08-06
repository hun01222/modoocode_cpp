#include <pthread.h>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) {
  for (int i = 0; i < 10000; i++) {
    // mutex 는 unique_ptr 와 동일
    // lock 생성 시에 m.lock() 을 실행
    std::lock_guard<std::mutex> lock(m);
    result += 1;
    
    // scope 를 빠져 나가면 lock 이 소멸되면서
    // m 을 알아서 unlock 한다
  }
}

int main() {
  int counter = 0;
  std::mutex m;
  
  std::vector<std::thread> workers;
  for (int i = 0; i < 4; i++)
    workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
  
  for (int i = 0; i < 4; i++)
    workers[i].join();
  
  std::cout << "Counter 최종 값 : " << counter << std::endl;
}