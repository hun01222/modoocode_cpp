// 스택 풀기: catch 로 점프하면서 스택 상에서 정의된 객체들을 소멸시키는 과정

#include <iostream>
#include <stdexcept>

class Resource {
 public:
  Resource(int id) : id_(id) {}
  ~Resource() { std::cout << "리소스 해제 : " << id_ << std::endl; }

 private:
  int id_;
};

int func3() {
  Resource r(3);
  throw std::runtime_error("Exception from 3!\n");
}
int func2() {
  Resource r(2);
  func3();
  std::cout << "실행 안됨!" << std::endl;
  return 0;
}
int func1() {
  Resource r(1);
  func2();
  std::cout << "실행 안됨!" << std::endl;
  return 0;
}

int main() {
  try {
    func1();
  } catch (std::exception& e){
    std::cout << "Exception : " << e.what();
  }
}