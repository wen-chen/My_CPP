#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>


void calc_fdr(const std::vector <double> & p_values, std::vector <double> & fdrs, int test_num) {
  // 生成一个带index的p_values, index用于还原fdr的位置
  int len = p_values.size();
  std::vector <std::pair <double, int> > p_values_index (len);
  for (int i = 0; i < len; ++i) {
    p_values_index[i].first = p_values[i];
    p_values_index[i].second = i;
  }

  // 从大到小排序
  std::sort(p_values_index.begin(), p_values_index.end(),
          [&](const std::pair <double, int> & a, const std::pair <double, int> & b) {
    return (a.first > b.first);
  });
  
  // 计算fdr
  double prev_fdr = 1.0;
  double fdr = 0.0;
  for (int i = 0; i < len; ++i) {
    fdr = p_values_index[i].first * test_num / (len - i);
    if (fdr < prev_fdr) {
      prev_fdr = fdr;
    }
    fdrs[p_values_index[i].second] = prev_fdr;
  }
}


int main() {
  std::vector <double> p_values = {0.28757752, 0.40897693, 0.05953272, 0.47189451, 0.44856499, 0.04316666,
                                   0.32242936, 0.10292469, 0.24608773, 0.32792072};
  std::vector <double> fdrs_R = {0.7026873, 0.7078418, 0.4464954, 0.7078418, 0.7078418, 0.4464954, 0.7026873,
                                 0.5146234, 0.7026873, 0.7026873};
  std::vector <double> fdrs(p_values.size(), 0);
  calc_fdr(p_values, fdrs, 15);
  for (int i = 0; i < fdrs.size(); ++i) {
    std::cout << "C++: " << fdrs[i] << "; R: " << fdrs_R[i] << std::endl;
  }
  return 0;
}
