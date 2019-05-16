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

const int N = 5e5 + 5;

int parent[N];
int cnt[N];
int res[N];
int nxt[N];
int n;
void addEdge(int p, int child) {
  parent[child] = p;
  ++cnt[p];
}

bool check() {
  for (int i = n; i >= 1; --i) {
    int curr = i + 1;
    while (curr < n + 1 && res[curr] < res[i]) {
      curr = nxt[curr];
    }
    if (curr != nxt[i]) return false;
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

  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> nxt[i];
      if (nxt[i] == -1) {
        nxt[i] = i + 1;
      }
      addEdge(nxt[i], i);
    }

    set<int> st;

    for (int i = 1; i <= n; ++i) {
      if (cnt[i] == 0) {
        st.insert(i);
      }
    }

    int val = 1;
    while (!st.empty()) {
      int curr = *st.rbegin();
      st.erase(curr);
      res[curr] = val;
      if (--cnt[parent[curr]] == 0 && parent[curr] != n + 1) {
        st.insert(parent[curr]);
      }
      ++val;
    }

    if (check()) {
      for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }

    memset(cnt, 0, (n + 2) * sizeof(cnt[0]));
  }

}
