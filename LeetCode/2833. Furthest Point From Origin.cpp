#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int furthestDistanceFromOrigin(string moves) {
    int n = moves.size();
    int sum = 0, cnt_ = 0;
    for (auto move : moves) {
      sum -= move == 'L';
      sum += move == 'R';
      cnt_ += move == '_';
    }
    return abs(sum) + cnt_;
  }
};