#include <iostream>
#include <memory>
#include <string>
#include <vector>

class A {
  std::string s;

  // weak_ptr는 일반 포인터와 shared_ptr 사이에 위치한 스마트 포인터
  // 스마트 포인터처럼 객체를 안전하게 참조, shared_ptr 과 다르게
  // 참조 개수를 늘리진 않음
  std::weak_ptr<A> other;

 public:
  A(const std::string& s) : s(s) { std::cout << "자원을 획득함!" << std::endl; }

  ~A() { std::cout << "소멸자 호출!" << std::endl; }

  void set_other(std::weak_ptr<A> o) { other = o; }
  void access_other() {
    std::shared_ptr<A> o = other.lock();
    if (o)
      std::cout << "접근 : " << o->name() << std::endl;
    else 
      std::cout << "이미 소멸됨" << std::endl;
  }
  std::string name() { return s; }
};

int main() {
  std::vector<std::shared_ptr<A>> vec;
  vec.push_back(std::make_shared<A>("자원1"));
  vec.push_back(std::make_shared<A>("자원2"));

  vec[0]->set_other(vec[1]);
  vec[1]->set_other(vec[0]);

  std::cout << "vec[0] ref count : " << vec[0].use_count() << std::endl;
  std::cout << "vec[1] ref count : " << vec[1].use_count() << std::endl;

  vec[0]->access_other();

  vec.pop_back();
  vec[0]->access_other();
}