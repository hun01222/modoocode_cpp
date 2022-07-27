#include <iostream>
#include <string>
using namespace std::literals;

int main() {
  auto s1 = "hello"s;
  std::cout << "s1 길이 : " << s1.size() << std::endl;
}