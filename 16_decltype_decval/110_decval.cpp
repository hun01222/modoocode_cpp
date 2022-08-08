#include <utility>

// std::declval 에 타입 T 를 전달하면, T 의 생성자를 직접 호출하지 않더라도 T 가 생성된 객체를 나타낼 수 있다.
template <typename T>
decltype(std::declval<T>().f()) call_f_and_return(T& t) {
  return t.f();
}

struct A {
  int f() { return 0; }
};

struct B {
  B(int x) {}
  int f() { return 0; }
};

int main() {
  A a;
  B b(1);
  
  call_f_and_return(a);
  call_f_and_return(b);
}