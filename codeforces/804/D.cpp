#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;

vector<int> adj[N];

int furth_down[N];
int furth_up[N];
int comp[N];
int size[N];
bool vis_up[N];

// for comps
vector<int> furth_non[N];
vector<Long> furth_acc[N];

void BuildDown(int node, int parent) {
  if (parent == -1) {
    comp[node] = node;
  } else {
    comp[node] = comp[parent];
  }

  ++size[comp[node]];

  int& res = furth_down[node];

  for (int v : adj[node]) {
    if (v == parent) continue;
    BuildDown(v, node);
    res = max(res, 1 + furth_down[v]);
  }
}

void BuildUp(int node, int parent) {
  vis_up[node] = true;
  if (parent != -1) {
    furth_up[node] = max(furth_up[node], 1 + furth_up[parent]);
  }

  for (int i = 0; i < 2; ++i) {
    int curr_mx = -5;
    for (int v : adj[node]) {
      if (v == parent) continue;
      furth_up[v] = max(furth_up[v], 2 + curr_mx);
      curr_mx = max(curr_mx, furth_down[v]);
    }
    reverse(adj[node].begin(), adj[node].end());
  }

  for (int v : adj[node]) {
    if (v == parent) continue;
    BuildUp(v, node);
  }
}

int n;
void Build() {
  for (int i = 1; i <= n; ++i) {
    if (comp[i] != 0) continue;
    BuildDown(i, -1);
  }

  for (int i = 1; i <= n; ++i) {
    if (vis_up[i]) continue;
    BuildUp(i, -1);
  }


  for (int i = 1; i <= n; ++i) {
    furth_non[comp[i]].push_back(max(furth_down[i], furth_up[i]));
  }

  for (int i = 1; i <= n; ++i) {
    sort(furth_non[i].begin(), furth_non[i].end());
    furth_acc[i].resize(furth_non[i].size() + 1);
    furth_acc[i].back() = 0;

    for (int j = furth_non[i].size() - 1; j >= 0; --j) {
      furth_acc[i][j] = furth_acc[i][j + 1] + furth_non[i][j];
    }
  }
}

map<pair<int, int>, double> queries;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int m, q;
  cin >> n >> m >> q;

  while (m--) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  Build();

  cout << fixed << setprecision(10);

  while (q--) {
    int u, v;
    cin >> u >> v;

    u = comp[u];
    v = comp[v];

    if (u == v) {
      cout << -1 << '\n';
      continue;
    }

    if (furth_non[u].size() > furth_non[v].size()) {
      swap(u, v);
    }

    if (queries.count( { u, v })) {
      cout << queries[ { u, v }] << '\n';
      continue;
    }

    double res = 0;

    int mn = max(furth_non[u].back(), furth_non[v].back());


    for (int d : furth_non[u]) {
      int ind = lower_bound(furth_non[v].begin(), furth_non[v].end(),
        mn - d - 1) - furth_non[v].begin();

      res += 1LL * (furth_non[v].size() - ind) * (d + 1);
      res += 1LL * ind * mn;

      res += furth_acc[v][ind];

    }

    res /= 1LL * furth_non[u].size() * furth_non[v].size();

    queries[ { u, v }] = res;

    cout << res << '\n';
  }

}
