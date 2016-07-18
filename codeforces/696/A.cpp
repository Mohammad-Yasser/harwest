#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

unordered_map<ll, ll> cost;

ll GetLca(ll u, ll v) {
  int fu = 63, fv = 63;
  while (((u >> fu) & 1LL) == 0) --fu;
  while (((v >> fv) & 1LL) == 0) --fv;
  u >>= fu - min(fu, fv);
  v >>= fv - min(fu, fv);
  while (u != v) u >>= 1, v >>= 1;
  return u;
}

ll GetAndUpdateCost(ll u, ll v, int w = 0) {
  ll cst = 0;
  while (u != v) {
    cst += (cost[u] += w);
    u >>= 1;
  }
  return cst;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    int t , w ;
    ll v, u;
    cin >> t >> v >> u;
    ll lca = GetLca(u, v);
    if (t == 1) {
      cin >> w;
      GetAndUpdateCost(u, lca, w);
      GetAndUpdateCost(v, lca, w);
    } else {
      cout << GetAndUpdateCost(u, lca) + GetAndUpdateCost(v, lca) << '\n';
    }
  }
}
