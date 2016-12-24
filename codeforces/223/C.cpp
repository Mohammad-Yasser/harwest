#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const int N = 2003;
const int MOD = 1000000007;

ll nCr[N];

int Power(int base, int p) {
  ll res = 1;
  ll curr = base;
  for (int i = 0; i < 32; ++i) {
    if ((p >> i) & 1) {
      res = res * curr % MOD;
    }
    curr = curr * curr % MOD;
  }
  return res;
}

void Build(int k) {
  nCr[0] = 1;
  for (int i = k + 1; i < N + k + 1; ++i) {
    nCr[i - k] = nCr[i - k - 1] * Power(i - k, MOD - 2) % MOD;
    nCr[i - k] = nCr[i - k] * i % MOD;
  }
}

int arr[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;
  --k;
  Build(k);

//  for (int i = 0; i < 5; ++i) {
//    cout << nCr[i] << ' ';
//  }
//  cout << endl;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    int res = 0;
    for (int j = 0; j <= i; ++j) {
      res = (res + 1LL * arr[j] * nCr[i - j]) % MOD;
    }
    cout << res << ' ';
  }

}
