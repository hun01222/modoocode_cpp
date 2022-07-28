#include <functional>
#include <iostream>

// bind 는 함수 객체 생성 시에 인자를 특정한 것으로 지정해준다.

struct S {
  int data;
  S(int data) : data(data) { std::cout << "일반 생성자 호출!" << std::endl; }
  S(const S& s) {
    std::cout << "복사 생성자 호출!" << std::endl;
    data = s.data;
  }
  S(S&& s) {
    std::cout << "이동 생성자 호출!" << std::endl;
    data = s.data;
  }
};

void do_something(S& s1, const S& s2) { s1.data = s2.data + 3; }

int main() {
  S s1(1), s2(2);

  std::cout << "Before : " << s1.data << std::endl;

  // std::placeholder 의 _1, _2 들은 일일이 정의된 객체들이다.
  // std::ref 는 s1 의 레퍼런스임을 명시적으로 정의해준다.
  auto do_something_with_s1 =
      std::bind(do_something, std::ref(s1), std::placeholders::_1);
  do_something_with_s1(s2);

  std::cout << "After :: " << s1.data << std::endl;
}
