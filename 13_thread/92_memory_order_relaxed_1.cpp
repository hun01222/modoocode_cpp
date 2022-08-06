#include <pthread.h>
#include <thread>
#include <atomic>
#include <cstdio>
#include <vector>
// memory_order_relaxed 방식으로 메모리에서 읽거나 쓸 경우,
// 주위의 다른 메모리 접근들과 순서가 바뀌어도 무방
// 해당 명령 이전의 모든 메모리 명령들이 해당 명령 이후로 재배치 되는 것을 금지
using std::memory_order_relaxed;

void t1(std::atomic<int>* a, std::atomic<int>* b) {
  // b = 1 (쓰기)
  b->store(1, memory_order_relaxed);
  
  // x = a (읽기)
  int x = a->load(memory_order_relaxed);
  
  printf("x : %d \n", x);
}

void t2(std::atomic<int>* a, std::atomic<int>* b) {
  a->store(1, memory_order_relaxed);
  int y = b->load(memory_order_relaxed);
  
  printf("y : %d \n", y);
}

int main() {
  std::vector<std::thread> threads;
  
  std::atomic<int> a(0);
  std::atomic<int> b(0);
  
  threads.push_back(std::thread(t1, &a, &b));
  threads.push_back(std::thread(t2, &a, &b));
  
  for (int i = 0; i < 2; i++)
    threads[i].join();
}