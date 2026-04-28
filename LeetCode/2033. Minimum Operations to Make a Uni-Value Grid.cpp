#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int minOperations(vector<vector<int>>& grid, int x) {
    int n = grid.size(), m = grid[0].size();
    vector<int> p(n * m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        p[i * m + j] = grid[i][j];
      }
    }
    sort(p.begin(), p.end());
    int median = p[n * m / 2];
    int ans = 0;
    for (auto v : p) {
      int need = abs(median - v);
      if (need % x) {
        return -1;
      }
      ans += need / x;
    }
    return ans;
  }
};
