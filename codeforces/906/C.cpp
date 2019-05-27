#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 22;

int uni[1 << N];
int adj[N];

int getLSB(int mask) {
  return mask & (-mask);
}

bool isConnected(int mask) {
  int curr = uni[getLSB(mask)] & mask;
  while ((uni[curr] & mask) != curr) {
    curr = (uni[curr] & mask);
  }
  return curr == mask;
}

int n;

bool validMask(int mask) {
  return popCnt(uni[mask]) == n && isConnected(mask);
}

vector<int> masks[N + 1];

int getMask(int cnt) {
  for (int mask : masks[cnt]) {
    if (validMask(mask)) return mask;
  }
  return -1;
}

int bs() {
  int low = 1, high = n, ans = (1 << n) - 1;

  for (int mid = n - 1; mid >= 1; --mid) {
    int tmp = getMask(mid);
    if (tmp != -1) {
      ans = tmp;
    }
  }
  return ans;
}

int lg[1 << N];

void build() {
  for (int i = 0; i < n; ++i) {
    lg[1 << i] = i;
  }

  for (int i = 1; i < (1 << n); ++i) {
    masks[popCnt(i)].push_back(i);
    uni[i] = (i | uni[i ^ getLSB(i)] | adj[lg[getLSB(i)]]);
  }
}

bool isZero() {
  for (int i = 0; i < n; ++i) {
    if (popCnt(adj[i] | (1 << i)) != n) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u] |= (1 << v);
    adj[v] |= (1 << u);
  }

  if (isZero()) {
    cout << 0;
    return 0;
  }

  build();

  int res = bs();
  cout << popCnt(res) << endl;
  for (int i = 0; i < n; ++i) {
    if ((res >> i) & 1) {
      cout << (i + 1) << " ";
    }
  }

}
