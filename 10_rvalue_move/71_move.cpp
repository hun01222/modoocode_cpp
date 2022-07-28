// move 함수는 좌측값을 우측값으로 바꿔준다.
// 좌측값 : int a = 3; 의 a처럼 주솟값을 취할 수 있는 값
// 우측값 : 위의 3처럼 주솟값을 취할 수 없는 값

#include <iostream>
#include <utility>

class A {
 public:
  A() { std::cout << "일반 생성자 호출!" << std::endl; }
  A(const A& a) { std::cout << "복사 생성자 호출!" <<std::endl; }
  A(A&& a) { std::cout << "이동 생성자 호출!" << std::endl; }
};

int main() {
  A a;

  std::cout << "-------------" << std::endl;
  A b(a);

  std::cout << "-------------" << std::endl;
  A c(std::move(a));
}