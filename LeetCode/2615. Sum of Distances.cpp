#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    vector<long long> arr(n);
    map<int, long long> sum;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      arr[i] += 1ll * cnt[nums[i]] * i - sum[nums[i]];
      sum[nums[i]] += i;
      cnt[nums[i]] += 1;
    }
    sum.clear();
    cnt.clear();
    for (int i = n - 1; i >= 0; i--) {
      arr[i] += sum[nums[i]] - 1ll * cnt[nums[i]] * i;
      sum[nums[i]] += i;
      cnt[nums[i]] += 1;
    }
    return arr;
  }
};