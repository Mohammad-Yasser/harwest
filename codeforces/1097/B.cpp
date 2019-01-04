#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 15;

int arr[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int mask = 0; mask < (1 << n); ++mask) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        sum += arr[i];
      } else {
        sum -= arr[i];
      }
    }
    sum = ((sum % 360) + 360) % 360;
    if (sum == 0) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
}
