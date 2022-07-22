#include<cstring>
#include<iostream>
#include<string>

// size_t 는 부호 없는 정수형으로 sizeof, alignof, offsetof 의 반환값이다.
// 메모리나 문자열 길이를 구할 때 사용한다.
size_t GetStringSize(const char *s) {return strlen(s);}

size_t GetStringSize(const std::string &s) {return s.size();}

template<typename String, typename... Strings>
size_t GetStringSize(const String &s, Strings... strs){
  return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string *concat_str) {return;}

template<typename String, typename... Strings>
void AppendToString(std::string *concat_str, const String &s, Strings... strs){
  concat_str->append(s);
  AppendToString(concat_str, strs...);
}

template<typename String, typename... Strings>
std::string StrCat(const String &s, Strings... strs){
  size_t total_size=GetStringSize(s, strs...);

  std::string concat_str;
  concat_str.reserve(total_size);

  concat_str=s;
  AppendToString(&concat_str, strs...);

  return concat_str;
}

int main(){
  std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a")
    , " ", std::string("sentence"));
}