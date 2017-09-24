#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 1e5 + 5;
const int X = 11;
const int MOD = round(1e9 + 7);

Long memo[N][X][2][2];
int n, m;
int k, x;

vector<int> adj[N];

Long solve(int node, int x, bool canHighest, bool canAnything, int parent);

void build(int node, bool canHighest, bool canAnything, int parent) {
  Long res[X];
  memset(res, 0, sizeof res);

  if (canHighest) {
    Long tmp[X][2];
    memset(tmp, -1, sizeof tmp);

    bool curr_p = 0;
    for (int v : adj[node]) {
      if (v == parent) continue;
      curr_p ^= 1;

      for (int i = 0; i < X; ++i) {
        Long& val = tmp[i][curr_p];
        if (tmp[i][curr_p ^ 1] == -1) {
          val = solve(v, i, false, false, node);
          continue;
        }
        val = 0;
        for (int j = 0; j <= i; ++j) {
          val = (val + tmp[i - j][curr_p ^ 1] * solve(v, j, false, false, node))
            % MOD;
        }
      }
    }

    for (int i = 0; i < X; ++i) {
      if (i == 0) continue;
      auto& val = tmp[i - 1][curr_p];
      if (val == -1) {
        val = (i == 1);
      }
      res[i] = (res[i] + val) % MOD;
    }
  }

  if (canAnything) {
    Long tmp[X][2];
    memset(tmp, -1, sizeof tmp);

    bool curr_p = 0;
    for (int v : adj[node]) {
      if (v == parent) continue;
      curr_p ^= 1;

      for (int i = 0; i < X; ++i) {
        Long& val = tmp[i][curr_p];

        if (tmp[i][curr_p ^ 1] == -1) {
          val = solve(v, i, false, true, node);
          continue;
        }
        val = 0;
        for (int j = 0; j <= i; ++j) {
          val = (val + tmp[i - j][curr_p ^ 1] * solve(v, j, false, true, node))
            % MOD;
        }
      }
    }

    for (int i = 0; i < X; ++i) {
      auto& val = tmp[i][curr_p];
      if (val == -1) {
        val = (i == 0);
      }
      val = val * (m - k) % MOD;
      res[i] = (res[i] + val) % MOD;
    }
  }

  {
    Long tmp[X][2];
    memset(tmp, -1, sizeof tmp);

    bool curr_p = 0;
    for (int v : adj[node]) {
      if (v == parent) continue;
      curr_p ^= 1;

      for (int i = 0; i < X; ++i) {
        Long& val = tmp[i][curr_p];
        if (tmp[i][curr_p ^ 1] == -1) {
          val = solve(v, i, true, true, node);
          continue;
        }
        val = 0;
        for (int j = 0; j <= i; ++j) {
          val = (val + tmp[i - j][curr_p ^ 1] * solve(v, j, true, true, node))
            % MOD;
        }
      }
    }

    for (int i = 0; i < X; ++i) {
      auto& val = tmp[i][curr_p];
      if (val == -1) {
        val = (i == 0);
      }
      val = val * (k - 1) % MOD;
      res[i] = (res[i] + val) % MOD;
    }
  }

  for (int i = 0; i < X; ++i) {
    memo[node][i][canHighest][canAnything] = res[i];
  }
}

Long solve(int node, int x, bool canHighest, bool canAnything, int parent) {
  if (x < 0) {
    return 0;
  }
  if (x == 0) {
    canHighest = false;
  }

  auto& res = memo[node][x][canHighest][canAnything];
  if (res != -1) return res;

  build(node, canHighest, canAnything, parent);
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> m;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cin >> k >> x;

  memset(memo, -1, sizeof memo);

  Long res = 0;
  for (int i = 0; i <= x; ++i) {
    res = (res + solve(1, i, true, true, -1)) % MOD;
  }

  cout << res << endl;
}
