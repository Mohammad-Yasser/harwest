#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Solve(ll n) {
  int ans = 0;
  --n;

  ll a = 0, b = 1;

  while (n >= b) {
    n -= b;
    ++ans;
    a += b;
    swap(a, b);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
//  freopen("o.txt", "wt", stdout);
#endif

  ll n;
  cin >> n;
  cout << Solve(n);

  return 0;
}
