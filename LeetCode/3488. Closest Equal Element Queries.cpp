#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    map<int, vector<int>> pos;
    int n = nums.size(), m = queries.size();
    for (int i = 0; i < n; i++) {
      pos[nums[i]].push_back(i);
    }
    vector<int> ans(m, -1);
    for (int i = 0; i < m; i++) {
      int j = queries[i];
      auto it = lower_bound(pos[nums[j]].begin(), pos[nums[j]].end(), j);
      int dist = 1E9;
      if (it != pos[nums[j]].begin()) {
        auto prev_it = prev(it);
        int new_dist = min(*it - *prev_it, n - *it + *prev_it);
        new_dist = min(new_dist, n - *it + pos[nums[j]].front());
        dist = min(dist, new_dist);
      }
      if (next(it) != pos[nums[j]].end()) {
        auto next_it = next(it);
        int new_dist = min(*next_it - *it, n - *next_it + *it);
        new_dist = min(new_dist, n - pos[nums[j]].back() + *it);
        dist = min(dist, new_dist);
      }
      if (dist != 1E9) {
        ans[i] = dist;
      }
    }
    return ans;
  }
};