#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 101;

int arr[N];
int joon[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
#endif
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    --arr[i];
  }

  ll lcm = 1;

  for (int i = 0; i < n; ++i) {
    ll cycle = 0;
    int x = i;
    do {
      ++cycle;
      x = arr[x];
    } while (x != i && cycle <= n);
    if (x != i) {
      cout << -1;
      return 0;
    }
    if (cycle % 2 == 0) cycle /= 2;
    lcm = lcm / __gcd(lcm, cycle) * cycle;
  }

  cout << lcm << '\n';
  return 0;
}
