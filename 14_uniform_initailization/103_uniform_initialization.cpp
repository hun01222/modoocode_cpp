// {} 를 사용하면 원하지 않는 타입 캐스팅을 방지해서 미연에 오류를 잡아낼 수 있다.
// {} 를 사용하면 함수 리턴 시에 굳이 생성하는 객체의 타입을 다시 명시 하지 않아도 된다.

#include <iostream>

class A {
 public:
  A(int x, double y) { std::cout << "A 생성자 호출" << std::endl; } 
};

A func() {
  return {1, 2.3};
}

int main() { func(); }