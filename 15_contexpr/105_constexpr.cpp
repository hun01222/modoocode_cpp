// 컴파일 타임에 어떤 식의 값을 결장할 수 있다면 해당 식을 상수식 (Constant Expression) 이라고 한다
// 상수식들 중에서 값이 정수인 것을 정수 상수식이라고 한다.

#include <iostream>

template <int N>
struct A {
  int operator()() { return N; }
};

int main() {
  constexpr int size = 3;
  int arr[size];
  
  constexpr int N = 10;
  A<N> a;
  std::cout << a() << std::endl;
  
  constexpr int number = 3;
  enum B { x = number, y, z };
  std::cout << B::x << std::endl;
  
  // int a;
  // constexpr int b = a;
  // error!
}