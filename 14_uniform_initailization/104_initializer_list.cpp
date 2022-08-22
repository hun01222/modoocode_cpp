#include <iostream>

class A {
 public:
  A(std::initializer_list<int> l) {
    for (auto itr = l.begin(); itr != l.end(); ++itr)
      std::cout << *itr << std::endl;
  }
};

// 컴파일러는 {} 를 이용하여 생성자를 호출하였을 경우 initializer_list 를 받는 생성자를 최우선으로 고려한다
int main() { A a = {1, 2, 3, 4, 5}; }