#include <vector>
#include <algorithm>
#include <iostream>

int main() {
  std::vector <std::vector <int>> triangle {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    
  for (int i = triangle.size() - 2; i >= 0; i--) {
    for (int j = i; j >= 0; --j) {
      triangle[i][j] = std::min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
    }
  }

  std::cout << triangle[0][0] << std::endl;

  return 0;
}
