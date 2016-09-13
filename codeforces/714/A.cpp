#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  ll l1, r1, l2, r2, k;

  cin >> l1 >> r1 >> l2 >> r2 >> k;

  l1 = max(l1, l2);
  r1 = min(r1, r2);
  if (l1 <= k && k <= r1) ++l1;
  cout << max(0LL, r1 - l1 + 1);
}