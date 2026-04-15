#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int closestTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
      if (words[i] == target) {
        int dist = abs(startIndex - i);
        ans = min(ans, n - dist);
        ans = min(ans, dist);
      }
    }
    if (ans == n + 1) {
      return -1;
    }
    return ans;
  }
};