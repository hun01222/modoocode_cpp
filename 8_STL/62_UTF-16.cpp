#include <iostream>
#include <string>

int main() {
  std::u16string u16_str = u"안녕하세요 모두의 코드에 오신 것을 환영합니다.";
  std::string jaum[] = {"ㄱ", "ㄲ", "ㄴ", "ㄷ", "ᄄ", "ᄅ", "ᄆ",
                        "ᄇ", "ᄈ", "ᄉ", "ᄊ", "ᄋ", "ᄌ", "ᄍ",
                        "ᄎ", "ᄏ", "ᄐ", "ᄑ", "ᄒ"};

  for (char16_t c : u16_str) {
    if(!(0xAC00 <= c && c <= 0xD7A3))
      continue;

    int offset = c - 0xAC00;
    int jaum_offset = offset / 0x24C;
    std::cout << jaum[jaum_offset];
  }
}