#include <iostream>

// noexcept 로 명시된 함수는 예외를 발생시키지 않는다고 믿고
// 만약 예외가 발생하게 되면 프로그램이 종료돼버린다.

int foo() noexcept {}

int bar() noexcept { throw 1; }

int main() {
  foo();
  try {
    bar();
  } catch (int x) {
    std::cout << "Error : " << x << std::endl;
  }
}