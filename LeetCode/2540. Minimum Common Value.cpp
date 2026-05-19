#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int l = 0, r = 0;
    while(l < n && r < m) {
      if (nums1[l] == nums2[r]) {
        return nums1[l];
      } else if (nums1[l] < nums2[r]) {
        l += 1;
      } else {
        r += 1;
      }
    }
    return -1;
  }
};