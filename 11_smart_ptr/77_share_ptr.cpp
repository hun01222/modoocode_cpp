#include <iostream>
#include <memory>
#include <vector>

class A {
  int *data;

 public:
  A() {
    data = new int[100];
    std::cout << "자원을 획득함!" << std::endl;
  }

  ~A() {
    std::cout << "소멸자 호출!" << std::endl;
    delete[] data;
  }
};

int main() {
  // 여러 개의 스마트 포인터가 하나의 객체를 같이 소유해야 하는 경우
  // 특정 자원을 몇 개의 객체에서 가리키는지 추적한 다음 0 이 되면
  // 해제를 시켜주는 방식의 포인터
  std::vector<std::shared_ptr<A>> vec;

  vec.push_back(std::shared_ptr<A>(new A()));
  vec.push_back(std::shared_ptr<A>(vec[0]));
  vec.push_back(std::shared_ptr<A>(vec[1]));

  std::cout << "첫 번째 소멸!" << std::endl;
  vec.erase(vec.begin());

  std::cout << "다음 원소 소멸!" << std::endl;
  vec.erase(vec.begin());

  std::cout << "마지막 원소 소멸!" << std::endl;
  vec.erase(vec.begin());

  std::cout << "프로그램 종료!" << std::endl;
}