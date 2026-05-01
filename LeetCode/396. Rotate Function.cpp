#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int maxRotateFunction(vector<int>& nums) {
    long long sum = 0, f0 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      f0 += 1ll * (i + 1) * nums[i];
      sum += nums[i];
    }
    long long cur = f0 - sum;
    long long ans = cur;
    for (int i = 0; i < n; i++) {
      long long total = cur + 1ll * n * nums[i] - sum;
      ans = max(ans, total);
      cur = total;
    }
    return ans;
  }
};
