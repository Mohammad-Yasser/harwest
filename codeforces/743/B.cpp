#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int Get(int n, ll k) {
  ll size = (1LL << (n + 1)) - 1;
  if (k == size / 2 + 1) return n + 1;
  if (k < size / 2 + 1) return Get(n - 1, k);
  return Get(n - 1, k - (size / 2 + 1));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  int n;
  ll k;
  cin >> n >> k;

  cout << Get(n, k);

}
