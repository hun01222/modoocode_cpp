#include <cctype>
#include <iostream>
#include <string>

// std::char_traits 는 문자와 문자열들 간에 간단한 연산을 제공해주는
// 클래스이므로 데이터를 저장하지 않는다. 따라서 모든 함수들은 static 이다.
// 이를 Stateless 라고 한다.
struct my_char_traits : public std::char_traits<char> {
  static int get_real_rank(char c) {
    if(isdigit(c))
      return c + 256;
    return c;
  }

  static bool lt(char c1, char c2) {
    return get_real_rank(c1) < get_real_rank(c2);
  }

  static int compare(const char* s1, const char* s2, size_t n){
    while (n-- != 0) {
      if (get_real_rank(*s1) < get_real_rank(*s2))
        return -1;
      if (get_real_rank(*s1) > get_real_rank(*s2))
        return 1;
      ++s1;
      ++s2;
    }
    return 0;
  }
};

int main() {
  std::basic_string<char, my_char_traits> my_s1 = "1a";
  std::basic_string<char, my_char_traits> my_s2 = "1a";

  std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha
            << (my_s1 < my_s2) << std::endl;

  std::string s1 = "1a";
  std::string s2 = "a1";

  std::cout << "일반 문자열 : " << std::boolalpha << (s1 < s2) << std::endl;
}