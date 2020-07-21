#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 2003;
vector<int> sacks;
int vis[N][N];
int vid;
void init() {
  sacks.clear();
  ++vid;
}
int n;
bool dfs(int ind, int a_size) {
  if (ind == sz(sacks)) return a_size == n;
  int& v = vis[ind][a_size];
  if (v == vid) return false;
  v = vid;
  return dfs(ind + 1, a_size) || dfs(ind + 1, a_size + sacks[ind]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    init();
    cin >> n;
    vector<int> p(2 * n);
    cin >> p;
    int last = 0;
    for (int x : p) {
      if (sacks.empty() || x > last) {
        sacks.emplace_back(1);
        last = x;
      } else {
        ++sacks.back();
      }
    }
    cout << (dfs(0, 0) ? "YES" : "NO") << endl;
  }
  return 0;
}