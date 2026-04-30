#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  const int INF = -1;
  int maxPathScore(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector dp(n, vector(m, vector<int>(k + 1, INF)));
    dp[0][0][0] = 0;
    int ans = INF;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int cost = grid[i][j] > 0;
        for (int a = 0; a + cost <= k; a++) {
          if (i > 0 && dp[i - 1][j][a] >= 0) {
            dp[i][j][a + cost] = max(dp[i][j][a + cost], dp[i - 1][j][a] + grid[i][j]);
          }
          if (j > 0 && dp[i][j - 1][a] >= 0) {
            dp[i][j][a + cost] = max(dp[i][j][a + cost], dp[i][j - 1][a] + grid[i][j]);
          }
        }
      }
    }
    for (int i = 0; i <= k; i++) {
      ans = max(ans, dp[n - 1][m - 1][i]);
    }
    return ans;
  }
};
