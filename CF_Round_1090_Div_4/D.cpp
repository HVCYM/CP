#include<bits/stdc++.h>
using namespace std;

const int N = (int)(1E6);
vector<int> prime, lP(N + 1, 0);

void getPrime() {
  for (int i = 2; i <= N; i++) {
    if (lP[i] == 0) {
      lP[i] = i;
      prime.push_back(i);
    }
    for (int j = 0; i * prime[j] <= N; j++) {
      lP[i * prime[j]] = prime[j];
      if (prime[j] == lP[i]) break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  getPrime();
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << 1ll * prime[i] * prime[i + 1] << " \n"[i + 1 == n];
    }
  }
  return 0;
}