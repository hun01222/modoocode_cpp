#include <pthread.h>
#include <iostream>
#include <thread>
#include <vector>

void worker(int& counter) {
  for (int i = 0; i < 10000; i++)
    counter += 1;
}

int main() {
  int counter = 0;
  
  // std::ref 특정 타입을 참조하는 객체를 만든다
  // & 과 다르게 타입만 같다면 참조대상을 바꿀 수 있다
  std::vector<std::thread> workers;
  for (int i = 0; i < 4; i++)
    workers.push_back(std::thread(worker, std::ref(counter)));
  
  for (int i = 0; i < 4; i++)
    workers[i].join();
  
  std::cout << "Counter 최종 값 : " << counter << std::endl;
}