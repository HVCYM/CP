#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int n = box.size(), m = box[0].size();
    for(int i = 0; i < n; i++) {
      for(int j = m - 1, k = m - 1; j >= 0; j--) {
        while(k > j && box[i][k] != '.') {
          k -= 1;
        }
        if(box[i][j] == '#') {
          swap(box[i][j], box[i][k]);
        } else if(box[i][j] == '*') {
          k = j;
        }
      }
    }
    vector<vector<char>> ans(m, vector<char>(n));
    for(int j = 0; j < m; j++) {
      for(int i = 0; i < n; i++) {
        ans[j][i] = box[n - i - 1][j];
      }
    }
    return ans;
  }
};