#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool rotateString(string s, string goal) {
    int n = s.size();
    int m = goal.size();
    if (n != m) {
      return false;
    }
    string tgt = goal + goal;
    for (int i = 0; i < n; i++) {
      if (tgt.substr(i, n) == s) {
        return true;
      }
    }
    return false;
  }
};
