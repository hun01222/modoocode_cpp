// fold 형식을 사용하면 재귀 함수 호출을 위해
// 배이스 케이스를 만들지 않아도 된다.

#include<iostream>

template<typename... Ints>
int sum_all(Ints... nums){
  // fold 식을 쓸 때 ()로 감싸줘야 함
  // unary left fold
  return (... + nums);
}

int main(){
  std::cout << sum_all(1, 4, 2, 3, 10) << std::endl;
}