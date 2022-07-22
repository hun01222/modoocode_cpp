#include<iostream>

template<typename T>
void print(T arg){
  std::cout << arg << std::endl;
}

// ...을 parameter peck 이라고 부른다.
template<typename T, typename... Types>
void print(T arg, Types... args){
  std::cout << arg << ", ";
  print(args...);
}

int main(){
  print(1, 3.1, "abc");
  print(1, 2, 3, 4, 5, 6, 7);
}