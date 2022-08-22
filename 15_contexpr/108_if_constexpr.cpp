#include <iostream>
#include <type_traits>

template <typename T>
void show_value(T t) {
  // if constexpr 은 조건이 반드시 bool 로 타입 변환될 수 있어야 하는 컴파일 타임 상수식이다
  // if constexpr 이 참이면 else 부분은 컴파일 되지 않는다
  if constexpr (std::is_pointer<T>::value) {
    sdt::cout << "포인터 이다 : " << *t << std::endl;
  } else {
    std::cout << "포인터가 아니다 : " << t << std::endl;
  }
}

int main() {
  int x = 3;
  show_value(x);
  
  int* p = &x;
  show_value(p);
}