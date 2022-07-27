#include <iostream>
#include <string>

int main() {
  // () 빼고 다 넣을 수 있음
  // () 넣기 위해 delimiter foo() 사용
  std::string str = R"foo((asdfasdf
이 안에는
어떤 것들이 와도
// 이런것도 되고
#define hasldfjalskdfj \n\n <--- Escape 안해도 됨
)";
)foo";

  std::cout << str;
}