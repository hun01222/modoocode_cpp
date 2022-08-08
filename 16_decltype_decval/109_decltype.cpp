#include <iostream>

// auto 와 달리 decltype 은 정확한 값을 표현해준다
// 컴파일 시에 decltype 은 전체 식이 타입으로 변환된다

struct A {
  double d;
};

int main() {
  int a = 3;
  decltype(a) b = 2; // int
  
  int& r_a = a;
  decltype(r_a) r_b = b; // int&
  
  int&& x = 3;
  decltype(x) y = 2; // int&&
  
  A* aa;
  decltype(aa->d) dd = 0.1;
}