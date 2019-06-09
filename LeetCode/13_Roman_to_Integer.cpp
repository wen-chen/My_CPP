#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int romanToInt(string s) {
  unordered_map <string, int> roman_dict = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50},
                                            {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
  int ans=0;
  int len=s.size();
  int pos=0;
  while (pos < len) {
    if (roman_dict.find(s.substr(pos, 2)) != roman_dict.end()) {
      ans += roman_dict[s.substr(pos, 2)];
      pos += 2;
    } else if (roman_dict.find(s.substr(pos, 1)) != roman_dict.end()) {
      ans += roman_dict[s.substr(pos, 1)];
      pos += 1;
    } else {
      break;
    }
  }
  return ans;

}



int main() {
  std::cout << romanToInt("III") << '\n';
  std::cout << romanToInt("IV") << '\n';
  std::cout << romanToInt("IX") << '\n';
  std::cout << romanToInt("LVIII") << '\n';
  std::cout << romanToInt("MCMXCIV") << '\n';

  return 0;
}

