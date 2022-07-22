#include<iostream>
#include<array>

template<typename T1, int num>
T1 add_num(T1 t){
  return t + num;
}

template<typename T2>
void print_array(const T2 &arr){
  for(int i=0; i<arr.size(); i++)
    std::cout << arr[i] << ' ';
  std::cout << std::endl;
}

int main(){
  int x=3;
  std::cout << "x : " << add_num<int, 5>(x) << std::endl;

  std::array<int, 5> arr1={1, 2, 3, 4, 5};
  std::array<int, 3> arr2={3, 4, 5};

  print_array(arr1);
  print_array(arr2);
}