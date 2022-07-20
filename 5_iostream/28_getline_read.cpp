#include<fstream>
#include<iostream>
#include<string>

int main(){
  std::ifstream in("text.txt");
  char buf[100];

  if(!in.is_open()){
    std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    return 0;
  }

// in이 true이기 위해서는 다음 입력 작업이 성종적이여만 하고
// 현재 스트림에 오류 플래그가 켜져 있지 않아야 한다.
  while(in){
    in.getline(buf, 100);
    std:: cout << buf << std::endl;
  }

  return 0;
}