#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
const ll OO = 1e15;
ll memo[N][8];
bool vis[N][8];

int grid[N][3];

bool GetBit(int mask, int bit) {
  return (mask >> bit) & 1;
}
int n;
bool ValidMask(int ind, int in_mask, int out_mask, ll& val) {
  if (out_mask == 0) return false;
  if (ind == n - 1 && out_mask != 4) {
    return false;
  }
  if (ind == 0 && in_mask != 1) {
    return false;
  }

  val = 0;

  bool prev = false;
  for (int i = 0; i < 3; ++i) {
    bool in = GetBit(in_mask, i);
    bool out = GetBit(out_mask, i);

    if (in || out || prev) {
      val += grid[ind][i];
    }

    if (prev && in && out) {
      return false;
    }

    prev = in ^ out ^ prev;
  }

  return !prev;
}

ll Solve(int ind, int in_mask) {
  if (ind == n) return 0;
  ll& ret = memo[ind][in_mask];
  if (vis[ind][in_mask]) return ret;
  vis[ind][in_mask] = true;
  ret = -OO;

  for (int out_mask = 0; out_mask < 8; ++out_mask) {
    ll val = 0;
    if (!ValidMask(ind, in_mask, out_mask, val)) continue;
    ret = max(ret, val + Solve(ind + 1, out_mask));
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[j][i];
    }
  }

  cout << Solve(0, 1);
}
