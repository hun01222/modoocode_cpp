#include<iostream>
#include<string>

int main(){
  std::string s;
  std::cin >> s;

  char peek=std::cin.rdbuf()->snextc();
  if(std::cin.fail()) std::cout << "Failed";
  std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
  std::cin >> s;
  std::cout << "다시 읽으면 : " << s << std::endl;
}