#include <functional>
#include <iostream>
#include <string>

// callable은 호출 가능한 모든 것들이다
// c++ 에서는 () 를 붙혀서 호출 할 수 있는 것이다.

int some_func1(const std::string& a) {
  std::cout << "Func1 호출! " << a << std::endl;
  return 0;
}

struct S {
  void operator()(char c) { std::cout << "Func2 호출! " << c << std::endl; }
};

// C 에서의 함수 포인터는 진짜 함수들만 보관할 수 있는 객체
// std::function 은 함수 뿐만 아니라 모든 callable 들을 보관할 수 있는 객체

int main() {
  std::function<int(const std::string&)> f1 = some_func1;
  std::function<void(char)> f2 = S();
  std::function<void()> f3 = []() { std::cout << "Func3 호출! " << std::endl; };

  f1("hello");
  f2('c');
  f3();
}