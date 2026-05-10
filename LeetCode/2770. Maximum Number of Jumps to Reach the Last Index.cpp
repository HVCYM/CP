#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int maximumJumps(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> cnt(n, 0);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (abs(nums[i] - nums[j]) <= target) {
          if (j == 0) {
            cnt[i] = max(cnt[i], cnt[j] + 1);
          } else if (cnt[j]) {
            cnt[i] = max(cnt[i], cnt[j] + 1);
          }
        }
      }
    }
    if (!cnt[n - 1]) {
      return -1;
    }
    return cnt[n - 1];
  }
};