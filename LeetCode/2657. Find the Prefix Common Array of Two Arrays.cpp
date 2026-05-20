#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> cnt(n + 1);
    vector<int> ans(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
      cnt[A[i]] += 1;
      cnt[B[i]] += 1;
      tot += cnt[A[i]] == 2;
      if (A[i] != B[i]) {
        tot += cnt[B[i]] == 2;
      }
      ans[i] = tot;
    }
    return ans;
  }
};