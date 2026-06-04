#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int totalWaviness(int num1, int num2) {
    int ans = 0;
    for (int i = num1; i <= num2; i++) {
      string s = to_string(i);
      int k = s.size();
      if (k < 3) continue;
      for (int j = 1; j + 1 < k; j++) {
        if (s[j] > max(s[j - 1], s[j + 1])) {
          ans += 1;
        }
        if (s[j] < min(s[j - 1], s[j + 1])) {
          ans += 1;
        }
      }
    }
    return ans;
  }
};