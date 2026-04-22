#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> ans;
    for (auto s : queries) {
      int n = s.size();
      for (auto d : dictionary) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          cnt += d[i] != s[i];
        }
        if (cnt < 3) {
          ans.push_back(s);
          break;
        }
      }
    }
    return ans;
  }
};