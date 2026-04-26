#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool containsCycle(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector lvl(n, vector<int>(m, -1));
    vector vst(n, vector<bool>(m, false));
    vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    auto isValidMove = [&](int x, int y) -> bool {
      if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
      }
      return true;
    };
    auto Bfs = [&](int a,  int b) -> bool {
      queue<pair<int, int>> q;
      lvl[a][b] = 0;
      q.push({a, b});
      while(!q.empty()) {
        int k = q.size();
        for (int i = 0; i < k; i++) {
          auto [x, y] = q.front();
          vst[x][y] = true;
          q.pop();
          for (auto [dx, dy] : moves) {
            if (!isValidMove(x + dx, y + dy) || vst[x + dx][y + dy] || grid[x + dx][y + dy] != grid[x][y]) {
              continue;
            }
            if (lvl[x + dx][y + dy] != -1) {
              return true;
            }
            lvl[x + dx][y + dy] = lvl[x][y] + 1;
            q.push({x + dx, y + dy});
          }
        }
      }
      return false;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vst[i][j]) continue;
        if (Bfs(i, j)) {
          return true;
        }
      }
    }
    return false;
  }
};
