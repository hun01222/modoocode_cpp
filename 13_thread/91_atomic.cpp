#include <pthread.h>
// 원자적 연산이란, CPU 가 명령어 1개로 처리하는 명령으로,
// 중간에 다른 쓰레드가 끼어들 여지가 전혀 없는 연산이다
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

void worker(std::atomic<int>& counter) {
  for (int i = 0; i < 10000; i++)
    counter++;
}

int main() {
  std::atomic<int> counter(0);
  
  std::vector<std::thread> workers;
  for (int i = 0; i < 4; i++)
    workers.push_back(std::thread(worker, ref(counter)));
  
  for (int i = 0; i < 4; i++)
    workers[i].join();
  
  std::cout << "Counter 최종 값 : " << counter << std::endl;
}