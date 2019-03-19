#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef unsigned long long Long;

const int N = 3e5 + 5;
const int MOD = round(1e9 + 7);

int arr[N];
int pow2[N];
int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  pow2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pow2[i] = 2LL * pow2[i - 1] % MOD;
  }

  sort(arr, arr + n);

  int res = 0;

  for (int i = 0; i < n; ++i) {
    int tmp = 1LL * (pow2[i] - 1) * arr[i] % MOD;
    tmp = (tmp - 1LL * (pow2[n - 1 - i] - 1) * arr[i] % MOD + MOD) % MOD;
    res = (res + tmp) % MOD;
  }

  cout << res;

}

