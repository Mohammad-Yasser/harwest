#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;

int cnt[N];

void Factorize(int x) {
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      ++cnt[i];
      if (i * i != x) {
        ++cnt[x / i];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("wa.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  while (n--) {
    int x;
    cin >> x;
    Factorize(x);
  }

  int res = 1;

  for (int i = 2; i < N; ++i) {
    res = max(res, cnt[i]);
  }
  cout << res;
}
