#include <iostream>
#include <string>

// 전역 함수로 new를 사용하면 모든 new 연산자들이 이 함수를 사용
void* operator new(std::size_t count) {
  std::cout << count << " byte 할당" << std::endl;
  return malloc(count);
}

int main() {
  std::cout << "s1 생성 --- " << std::endl;
  std::string s1 = "this is a pretty long sentence!!!";
  std::cout << "s1 크기 : " << sizeof(s1) << std::endl;

  // 짧은 길이 문자열은 문자 데이터를 위한 메모리를 할당하지 않고 객체 자체에 저장
  std::cout << "s2 생성 --- " << std::endl;
  std::string s2 = "short sentence!!!";
  std::cout << "s2 크기 : " << sizeof(s2) << std::endl;
}