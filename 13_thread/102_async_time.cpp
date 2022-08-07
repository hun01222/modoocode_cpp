#include <pthread.h>
#include <future>
#include <iostream>
#include <thread>
#include <ctime>

int do_work(int x) {
  std::this_thread::sleep_for(std::chrono::seconds(3));
  return x;
}

void do_work_parallel() {
  auto f1 = std::async([]() { do_work(3); });
  auto f2 = std::async([]() { do_work(3); });
  do_work(3);
  
  f1.get();
  f2.get();
}

void do_work_sequential() {
  do_work(3);
  do_work(3);
  do_work(3);
}

int main() {
	clock_t start, end;
  double result;
  start = clock();
  
  do_work_parallel();
  
  end = clock();
  result = (double)(end - start);
  printf("%f\n", result);
  
  
  start = clock();
  
  do_work_sequential();
  
  end = clock();
  result = (double)(end - start);
  printf("%f", result);
}