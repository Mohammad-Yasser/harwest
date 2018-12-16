//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse4.1,sse4.2,ssse3,sse3,sse2,sse,avx")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 1e5 + 5;

vector<int> adj[N];

bool vis[N][2];
bool in_process[N];

bool cycle = false;
int nxt[N];
stack<int> st;

bool dfs(int node, bool par, bool alter) {
  if (!alter && in_process[node]) {
    cycle = true;
    return false;
  }
  if (adj[node].empty()) return par;
  if (vis[node][par]) return false;
  vis[node][par] = true;
  in_process[node] = true;
  for (int v : adj[node]) {
    if (dfs(v, par ^ alter, alter)) {
      st.push(v);
      return true;
    }
  }
  in_process[node] = false;
  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    adj[i].resize(x);
    for (int& v : adj[i]) {
      cin >> v;
    }
  }

  int s;
  cin >> s;

  if (dfs(s, 0, 1)) {
    cout << "Win" << endl;
    st.push(s);
    while (!st.empty()) {
      cout << st.top() << " ";
      st.pop();
    }
    return 0;
  }

  memset(vis, 0, sizeof vis);
  memset(in_process, 0, sizeof in_process);

  dfs(s, 0, 0);

  if (cycle) {
    cout << "Draw";
  } else {
    cout << "Lose";
  }
}
