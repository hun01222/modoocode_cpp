#include<fstream>
#include<iostream>
#include<string>

int main(){
  std::ifstream in("other.txt", std::ios::binary);
  std::string s;

  int x;
  if(in.is_open()){
    in.read((char*)(&x), 4); // 4byte씩 읽어라
    std::cout << std::hex << x << std::endl;
  }else{
    std::cout << "파일을 찾을 수 없습니다!" << std::endl;
  }
  
  return 0;
}