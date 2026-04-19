#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;
    int n = nums1.size(), m = nums2.size();
    for (int i = 0; i < n; i++) {
      int low = i - 1, high = m + 1;
      while(high - low > 1) {
        int mid = (low + high) >> 1;
        if (mid < m && nums2[mid] >= nums1[i]) {
          low = mid;
        } else {
          high = mid;
        }
      }
      ans = max(ans, low - i);
    }
    return ans;
  }
};