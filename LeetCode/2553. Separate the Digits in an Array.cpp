#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<int> separateDigits(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
      int j = nums[i];
      while(j > 0) {
        int r = j % 10;
        ans.push_back(r);
        j /= 10;
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};