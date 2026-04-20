#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int maxDistance(vector<int>& colors) {
    int n = colors.size();
    if (colors.front() != colors.back()) {
      return n - 1;
    }
    int ans = 0;
    for (int i = n - 2; i > 0; i--) {
      if (colors[i] != colors[0]) {
        ans = max(ans, i);
      }
      if (colors[i] != colors[n - 1]) {
        ans = max(ans, n - 1 - i);
      }
    }
    return ans;
  }
};