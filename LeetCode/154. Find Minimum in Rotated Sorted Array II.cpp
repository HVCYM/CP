#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      if (nums[mid] < nums[high]) {
        high = mid;
      } else if (nums[mid] > nums[high]) {
        low = mid;
      } else {
        high--;
      }
    }
    return min(nums[low], nums[high]);
  }
};