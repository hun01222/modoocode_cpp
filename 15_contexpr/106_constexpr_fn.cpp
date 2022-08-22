#include <iostream>

constexpr int Factorial(int n) {
  int total = 1;
  for (int i = 1; i <= n; i++)
    total *= i;
  return total;
}

template <int N>
struct A {
  int operator()() { return N; }
};

int main() {
  A<Factorial(10)> a;
  // 만약 constexpr fn 에 컴파일 타임 상수가 인자로 들어가지 않았어도 그냥 함수처럼 동작한다
  
  std::cout << a() << std::endl;
}