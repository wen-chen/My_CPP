#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>


int lengthOfLongestSubstring(std::string s) {
  int ans = 0;
  std::unordered_map <char, int> char_idx;

  for (int right = 0, left = 0; right < s.size(); ++right) {
    if (char_idx.find(s[right]) != char_idx.end()) {
      left = std::max(char_idx[s[right]], left);
    }
    ans = std::max(ans, right - left + 1);
    char_idx[s[right]] = right + 1;
  }

  return ans;
}

int main() {
  std::cout << lengthOfLongestSubstring("abcabcbb") << std::endl;
  std::cout << lengthOfLongestSubstring("bbbbb") << std::endl;
  std::cout << lengthOfLongestSubstring("pwwkew") << std::endl;
  std::cout << lengthOfLongestSubstring("a") << std::endl;
  std::cout << lengthOfLongestSubstring("dvdf") << std::endl;
  std::cout << lengthOfLongestSubstring("") << std::endl;

  return 0;
}