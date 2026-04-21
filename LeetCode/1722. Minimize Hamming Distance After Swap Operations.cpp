#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    int n = source.size();
    vector<int> par(n);
    iota(par.begin(), par.end(), 0);
    auto find = [&](int x) {
      while(x != par[x]) {
        x = par[par[x]];
      }
      return x;
    };
    auto unite = [&](int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) {
        return;
      }
      if (x > y) {
        swap(x, y);
      }
      par[y] = x;
    };
    map<int, int> cnt[n];
    for (auto swaps : allowedSwaps) {
      int x = swaps[0], y = swaps[1];
      unite(x, y);
    }
    for (int i = 0; i < n; i++) {
      int p = find(i);
      cnt[p][source[i]] += 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int p = find(i);
      if (!cnt[p].count(target[i])) {
        ans += 1;
      } else {
        cnt[p][target[i]]--;
        if (cnt[p][target[i]] == 0) {
          cnt[p].erase(target[i]);
        }
      }
    }
    return ans;
  }
};
/*
[[0, 1], [1, 2], [2, 3], [4, 5], [6, 7], [7, 8]]
[0, 1, 2, 3, 4, 5, 6, 7, 8]
par[0] = 0;
par[1] = 0;
par[2] = 0;
par[3] = 0;
par[4] = 4;
par[5] = 4;
par[6] = 6;
par[7] = 6;
par[8] = 6;
*/