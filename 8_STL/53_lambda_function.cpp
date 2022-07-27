#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
  while (begin != end) {
    std::cout << "[" << *begin << "] ";
    begin++;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vec;
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  std::cout << "처음 vec 상태 -----" << std::endl;
  print(vec.begin(), vec.end());

  std::cout << "벡터에서 홀수인 원소 2개 제거 ---" << std::endl;
  int num_erased = 0;

  // [capture list] (받는 인자) -> 리턴 타입 {함수 본체}
  // [] : 아무것도 캡쳐 안함
  // [&a, b]: a는 래퍼런스로 캡쳐, b는 (변경 불가능한) 복사본으로 캡쳐
  vec.erase(std::remove_if(vec.begin(), vec.end(),
                          [&num_erased](int i) -> bool {
                            if (num_erased >= 2){
                              return false;  
                            } else if(i % 2 == 1){
                              num_erased++;
                              return true;
                            } return false;
                          }),
            vec.end());
  print(vec.begin(), vec.end());
}