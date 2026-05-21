#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<string, bool> found;
    for (auto a : arr1) {
      string s = to_string(a);
      string t;
      for (auto c : s) {
        t += c;
        found[t] = true;
      }
    }
    int ans = 0;
    for (auto a : arr2) {
      string s = to_string(a);
      string t;
      for (auto c : s) {
        t += c;
        if (found.count(t)) {
          ans = max(ans, (int) t.size());
        }
      }
    }
    return ans;
  }
};