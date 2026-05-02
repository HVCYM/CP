#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int rotatedDigits(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int j = i;
      bool ok = true;
      int mx = 0;
      while(j > 0) {
        int r = j % 10;
        if (r != 8) {
          mx = max(mx, r);
        }
        j /= 10;
        if (r == 3 || r == 4 || r == 7) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << i << " " << mx << '\n';
        ans += mx > 1;
      }
    }
    return ans;
  }
};
