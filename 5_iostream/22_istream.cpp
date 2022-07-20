#include<iostream>
#include<string>

int main(){
  int t;
  while(true){
    std::cin >> t;
    std::cout << "입력 :: " << t << std::endl;
    if(std::cin.fail()){
      std::cout << "제대로 입력해주세요" << std::endl;
      std::cin.clear();
      std::cin.ignore(100, '\n'); // 최대 100자까지 개행문자가 나올 때 까지 무시
    }
    if(t==0) break;
  }
}