#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int mirrorDistance(int n) {
    string t = to_string(n);
    while(t.back() == '0') {
      t.pop_back();
    }
    reverse(t.begin(), t.end());
    int rev_n = stoi(t);
    return abs(n - rev_n);
  }
};