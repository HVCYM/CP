#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int minMirrorPairDistance(vector<int>& nums) {
    map<int, int> f;
    int n = nums.size();
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
      int a = nums[i];
      int rev_a = 0;
      while (a % 10 == 0) {
        a /= 10;
      }
      while(a > 0) {
        int r = a % 10;
        rev_a  = rev_a * 10 + r;
        a /= 10;
      }
      if (f.count(nums[i])) {
        ans = min(ans, i - f[nums[i]]);
      }
      f[rev_a] = i;
    }
    if (ans == n + 1) {
      return -1;
    }
    return ans;
  }
};