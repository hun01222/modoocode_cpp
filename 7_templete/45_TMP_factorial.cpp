#include<iostream>
template <int N>
struct Factorial{
  // 내부 계산 결과를 value로 반환
  static const int result=N*Factorial<N-1>::result;

template <>
struct Factorial<1>{
  static const int result=1;
};

int main(){
  std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;
}