#include<iostream>
#include<string>

class Base{
 protected:
  std::string parent_string;

 public:
  Base() : parent_string("기반") {std::cout << "기반 클래스" << std::endl;}

  virtual void what() {std::cout << parent_string << std::endl;}
};
class Derived : public Base{
  std::string child_string;

 public:
  Derived() : Base(), child_string("파생"){std::cout << "파생 클래스" << std::endl;}

  void what() override {std::cout << child_string << std::endl;}
};
int main(){
  Base p;
  Derived c;
  
  std::cout << "=== 포인터 버전 ===" << std::endl;
  Base *p_c=&c; // 업케스팅
  Base *p_p=&p;

  p_p->what();
  p_c->what(); // 동적 바인딩: 컴파일 시 어떤 함수가 실행될 지 정해지지 않고 런타임 시에 정해짐

  return 0;
}