#include<iostream>
#include<string>

class Base{
 protected:
  std::string parent_string;

 public:
  Base() : parent_string("기반") {std::cout << "기반 클래스" << std::endl;}

  void what() {std::cout << parent_string << std::endl;}
};
class Derived : public Base{
  std::string child_string;

 public:
  Derived() : Base(), child_string("파생"){std::cout << "파생 클래스" << std::endl;}

  void what() {std::cout << child_string << std::endl;}
};
int main(){
  Base p;
  Derived c;
  
  std::cout << "=== 포인터 버전 ===" << std::endl;
  Base *p_c=&c; // 업케스팅
  p_c->what();

  return 0;
}