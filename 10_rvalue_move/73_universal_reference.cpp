#include <iostream>

// 보편적 레퍼런스 T&& u 는 우측값만 받는 레퍼런스와 다르다!
template <typename T>
void wrapper(T&& u) {
  g(std::forward<T>(u));
}

class A {};

void g(A& a) { std::cout << "좌측값 레퍼런스 호출" << std::endl; }
void g(const A& a) { std::cout << "좌측값 상수 레퍼런스 호출" << std::endl; }
void g(A&& a) { std::cout << "우측값 레퍼런스 호출" << std::endl; }

int main() {
  A a;
  const A ca;

  std::cout << "원본 -------" << std::endl;
  g(a);
  g(ca);
  g(A());

  std::cout << "Wrapper ----" << std::endl;
  wrapper(a);
  wrapper(ca);
  wrapper(A());
}