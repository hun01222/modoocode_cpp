#include <iostream>
#include <memory>

// RAII : 포인터를 객체로 만들어서 생성과 동시에 초기화
// smart ptr : 객체가 소멸될 때 자신이 가지고 있는 데이터도 같이 delete
class A {
  int *data;

 public:
  A() {
    std::cout << "자원을 획득함!" << std::endl;
    data = new int[100];
  }

  void some() { std::cout << "일반 포인터와 동일하게 사용가능!" << std::endl; }

  ~A() {
    std::cout << "자원을 해제함!" << std::endl;
    delete[] data;
  }
};

void do_something() {
  std::unique_ptr<A> pa(new A());
  std::cout << "pa : ";
  pa->some();

// pb로 소유권 이전
  std::unique_ptr<A> pb = std::move(pa);
  std::cout << "pb : ";
  pb->some();
}

int main() { do_something(); }