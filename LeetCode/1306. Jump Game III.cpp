#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    vector<int> visited(n, false);
    queue<int> q;
    auto isBadMove = [&](int idx) -> bool {
      return (idx < 0 || idx >= n || visited[idx]);
    };
    auto add = [&](int idx) -> bool {
      if (isBadMove(idx)) return false;
      visited[idx] = true;
      q.push(idx);
      return true;
    };
    add(start);
    while (!q.empty()) {
      int currIdx = q.front();
      q.pop();
      if (arr[currIdx] == 0) {
        return true;
      }
      add(currIdx + arr[currIdx]);
      add(currIdx - arr[currIdx]);
    }
    return false;
  }
};