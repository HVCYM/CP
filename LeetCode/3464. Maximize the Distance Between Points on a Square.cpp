#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int maxDistance(int side, vector<vector<int>>& points, int k) {
    vector<vector<pair<int, int>>> p(4);
    for (auto point : points) {
      int x = point[0], y = point[1];
      if (y == 0) {
        p[0].push_back({x, y});
      } else if (x == side) {
        p[1].push_back({x, y});
      } else if (y == side) {
        p[2].push_back({x, y});
      } else {
        p[3].push_back({x, y});
      }
    }
    for (int i = 0; i < 4; i++) {
      if (p[i].empty()) continue;
      sort(p[i].begin(), p[i].end());
      if (i > 1) {
        reverse(p[i].begin(), p[i].end());
      }
    }
    int n = points.size();
    vector<pair<int, int>> pp;
    for (int i = 0 ; i < 4; i++) {
      for (auto c : p[i]) {
        pp.push_back(c);
      }
    }
    auto isPossible = [&](int mid) -> bool {
      for (int i = 0; i < min(n, 100); i++) {
        int cnt = 1;
        auto [start_x, start_y] = pp[i];
        auto [x, y] = pp[i];
        for (int j = 0; j < n; j++) { // this part can optimized using binary search / lower_bound
          auto [new_x, new_y] = pp[(i + j) % n];
          int dist = abs(new_x - x) + abs(new_y - y);
          if (dist >= mid) {
            x = new_x, y = new_y;
            cnt += 1;
          }
          if (cnt == k && (abs(start_x - x) + abs(start_y - y)) >= mid) {
            return true;
          }
        }
      }
      return false;
    };
    int low = 0, high = side + 1;
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if (isPossible(mid)) {
        low = mid;
      } else {
        high = mid;
      }
    }
    return low;
  }
};
