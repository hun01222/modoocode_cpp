#include <iostream>
#include <memory>

// std::enable_shared_from_this 는 같은 객체에 두 개의
// 다른 제어 블록이 생성되는 것을 막는다.
class A : public std::enable_shared_from_this<A> {
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

  std::shared_ptr<A> get_shared_ptr() { return shared_from_this(); }
};

int main() {
  std::shared_ptr<A> pa1 = std::make_shared<A>();
  std::shared_ptr<A> pa2 = pa1->get_shared_ptr();
  
  std::cout << pa1.use_count() << std::endl;
  std::cout << pa2.use_count() << std::endl;
}