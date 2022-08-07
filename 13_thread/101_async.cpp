#include <pthread.h>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

int sum(const std::vector<int>& v, int start, int end) {
  int total = 0;
  for (int i = start; i < end; i++)
    total += v[i];
  return total;
}

// std::async 에 어떤 함수를 전달한다면, 아예 쓰레드를 알아서 만들어서
// 해당 함수를 비동기적으로 실행하고, 그 결과값을 future 에 전달한다
int parallel_sum(const std::vector<int>& v) {
  std::future<int> lower_half_future =
    std::async(std::launch::async, sum, cref(v), 0, v.size() / 2);
  
  int upper_half = sum(v, v.size() / 2, v.size());
  
  return lower_half_future.get() + upper_half;
}

int main() {
  std::vector<int> v;
  v.reserve(1000);
  
  for (int i = 0; i < 1000; ++i) {
    v.push_back(i + 1);
  }
  
  std::cout << "1 부터 1000 까지의 합 : " << parallel_sum(v) << std::endl;
}