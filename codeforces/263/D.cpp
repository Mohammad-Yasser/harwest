#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef double Double;

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

const int N = 1e5 + 5;

vector<int> adj[N];
int depth[N];
stack<int> st;
int k;
void dfs(int node) {
  st.emplace(node);

  for (int v : adj[node]) {
    if (depth[v] == 0) {
      depth[v] = depth[node] + 1;
      dfs(v);
    } else if (depth[node] - depth[v] + 1 > k) {
      int r = depth[node] - depth[v] + 1;
      cout << r << endl;
      while (r--) {
        cout << st.top() << " ";
        st.pop();
      }
      cout << endl;
      exit(0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m >> k;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  depth[1] = 1;
  dfs(1);
  return 0;
}