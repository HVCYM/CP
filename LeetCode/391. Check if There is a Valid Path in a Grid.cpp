#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool hasValidPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    auto isValidMove = [&](int x, int y) -> bool {
      if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
      }
      return true;
    };
    vector<vector<pair<int, int>>> moves = {
      {{0, -1}, {0, 1}},
      {{-1, 0}, {1, 0}},
      {{0, -1}, {1, 0}},
      {{0, 1}, {1, 0}},
      {{0, -1}, {-1, 0}},
      {{0, 1}, {-1, 0}}};
    vector vst(n, vector<bool>(m, false));
    auto Dfs = [&](auto &&self, int x, int y) -> bool {
      if (x == n - 1 && y == m - 1) {
        return true;
      }
      vst[x][y] = true;
      for (auto [dx, dy] : moves[grid[x][y] - 1]) {
        if (!isValidMove(x + dx, y + dy) || vst[x + dx][y + dy]) continue;
        int x1 = x + dx, y1 = y + dy;
        bool ok = false;
        for (auto [dx1, dy1] : moves[grid[x1][y1] - 1]) {
          if (!isValidMove(x1 + dx1, y1 + dy1)) continue;
          int x2 = x1 + dx1, y2 = y1 + dy1;
          if (x2 == x && y2 == y) {
            ok = true;
            break;
          }
        }
        if (!ok) {
          break;
        }
        if (self(self, x1, y1)) {
          return true;
        }
        vst[x][y] = false;
      }
      return false;
    };
    return Dfs(Dfs, 0, 0);
  }
};
