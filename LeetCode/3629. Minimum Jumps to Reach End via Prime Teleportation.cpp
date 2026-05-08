#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int minJumps(vector<int>& nums) {
    int N = *max_element(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> lp(N + 1);
    iota(lp.begin(), lp.end(), 0);
    lp[0] = lp[1] = 0;
    for (int i = 2; i <= N; i++) {
      if (lp[i] < i) continue;
      for (int j = 2 * i; j <= N; j += i) {
        lp[j] = min(lp[j], i);
      }
    }
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
      if (lp[nums[i]] < nums[i]) continue;
      pos[nums[i]].push_back(i);
    }
    queue<int> q;
    q.push(n - 1);
    int jump = -1;
    vector<int> vst(n);
    vst[n - 1] = 1;
    while (!q.empty()) {
      int k = q.size();
      jump += 1;
      while (k--) {
        int f = q.front();
        q.pop();
        cout << f << " \n"[k == 0];
        if (f == 0) {
          return jump;
        }
        if (f + 1 < n && !vst[f + 1]) {
          q.push(f + 1);
          vst[f + 1] = 1;
        }
        if (f - 1 >= 0 && !vst[f - 1]) {
          q.push(f - 1);
          vst[f - 1] = 1;
        }
        int j = nums[f];
        while (j > 1) {
          int p = lp[j];
          if (pos.count(p)) {
            for (auto idx : pos[p]) {
              if (!vst[idx]) {
                q.push(idx);
                vst[idx] = 1;
              }
            }
          }
          while (j % p == 0) {
            j /= p;
          }
        }
      }
    }
    return -1;
  }
};