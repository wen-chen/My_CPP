#include <vector>
#include <algorithm>
#include <iostream>

double findMedianSortedArrays(std::vector <int>& nums1, std::vector <int>& nums2) {
  int m = nums1.size();
  int n = nums2.size();

  if (m > n) {
    return findMedianSortedArrays(nums2, nums1);
  }

  if (m == 0 and n > 0) {
    if (n % 2 == 0) {
      return (nums2[n / 2 - 1] + nums2[n / 2]) * 0.5;
    } else {
      return nums2[n / 2];
    }
  }
  
  /*
  nums1的长度为m, nums2的长度为n, 用i, j分别将两个数组分成两部分，分别为nums1_left, nums1_right, nums2_left, nums2_right
  将nums1_left, nums2_left归为nums_left; 将nums1_right, nums2_right归为nums_right
  
  只要保证:
  1. len(nums_left) = len(nums_right)
  2. max(nums_left) <= min(nums_left)
  那么中位数就是(max(nums_left) + min(nums_left)) / 2

  为了满足条件1, 需要使得i + j = m - i + n -i, 则j = (m + n + 1) / 2
  为了满足条件2, 需要使得nums1[i - 1] <= nums2[i]和nums2[j - 1] <= nums1[i]
  所以, 我们只要找到满足条件的i的位置即可
  */

  int imin = 0;
  int imax = m;
  double max_left, min_right;

  while (imin <= imax) {
    int i = (imin + imax) / 2;
    int j = (m + n + 1) / 2 - i;
    
    if (i < m and nums1[i] < nums2[j -1]) {  // i太小
      imin = i + 1;
    } else if (i > 0 and j < n and nums1[i - 1] > nums2[j]) { // i太大
      imax = i - 1;
    } else { // i合适            
      if (i == 0) {
        max_left = nums2[j - 1];        
      } else if (j == 0) {
        max_left = nums1[i - 1];
      } else {
        max_left = std::max(nums1[i-1], nums2[j-1]);        
      }

      if ((m + n) % 2 == 1) {
        return max_left;
      }

      if (i == m) {
        min_right = nums2[j];
      } else if (j == n) {
        min_right = nums1[i];
      } else {
        min_right = std::min(nums1[i], nums2[j]);      
      }
      
      return (max_left + min_right) * 0.5;     
    }
  } 
}


int main() {
  std::vector <int> nums1 {1, 3};
  std::vector <int> nums2 {2};
  std::vector <int> nums3 {1, 2};
  std::vector <int> nums4 {3, 4};
  std::vector <int> nums5 {};
  std::vector <int> nums6 {1};
  std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
  std::cout << findMedianSortedArrays(nums3, nums4) << std::endl;
  std::cout << findMedianSortedArrays(nums5, nums6) << std::endl;
  return 0;
}