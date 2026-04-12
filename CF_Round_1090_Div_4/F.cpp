#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      cout << "NO" << '\n';
      continue;
    }
    int n = x + y, d = y - x;
    int parity = n % 2;
    if ((parity != d % 2) || (parity == 0 && x == 0) || (parity == 1 && y == 0)) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 1; i < n - d; i++) {
      cout << i << " " << i + 1 << '\n';
    }
    for (int i = n; i > max(n - d, 1); i--) {
      cout << max(n - d, 1) << ' ' << i << '\n';
    }
  }
  return 0;
}