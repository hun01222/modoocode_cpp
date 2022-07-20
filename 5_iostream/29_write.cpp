#include<iostream>
#include<fstream>
#include<string>

int main(){
  // std::ios::app: 덧붙이기
  std::ofstream out("text.txt", std::ios::app);

  std::string s;
  if(out.is_open()){
    out << "이걸 쓰자!";
  }

  return 0;
}