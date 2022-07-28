#include <iostream>
#include <memory>
#include <vector>

class A {
  int *data;

 public:
  A(int i) {
    std::cout << "자원을 획득함!" << std::endl;
    data = new int[100];
    data[0] = i;
  }

  void some() { std::cout << "값 : " << data[0] << std::endl; }

  ~A() {
    std::cout << "자원을 해제함!" << std::endl;
    delete[] data;
  }
};

int main() {
  std::vector<std::unique_ptr<A>> vec;

  // vector 안에 unique_ptr 을 직접 생성하면서 집어넣을 수 있다.
  vec.emplace_back(new A(1));

  vec.back()->some();
}