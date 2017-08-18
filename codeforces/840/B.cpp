#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

bool vis[N];
int d[N];

enum State {
  ZERO, ONE, BOTH,
};

State state[N];

struct Edge {
  int to;
  int ind;
};

int curr_edge;

vector<Edge> adj[N], children[N];

void buildState(int node) {
  vis[node] = true;

  for (auto& edge : adj[node]) {
    int v = edge.to;
    if (vis[v]) continue;
    children[node].push_back(edge);

    buildState(v);
  }

  bool curr_d = 0;
  bool can = (d[node] == -1);

  for (auto& edge : children[node]) {
    int v = edge.to;
    State st = state[v];

    if (st == ONE) {
      curr_d ^= 1;
    }
    if (st == BOTH) {
      can = true;
    }
  }


  if (can) {
    state[node] = BOTH;
    return;
  }

  if (curr_d != d[node]) {
    state[node] = ONE;
  } else {
    state[node] = ZERO;
  }
}

vector<int> taken_edges;

void chooseEdges(int node) {
  bool curr_d = 0;

  for (auto& edge : children[node]) {
    int v = edge.to;
    State st = state[v];

    if (st == ONE) {
      taken_edges.push_back(edge.ind);
      d[v] ^= 1;
      curr_d ^= 1;
    }
  }

  if (curr_d == d[node] || d[node] == -1) goto end;

  for (auto& edge : children[node]) {
    int v = edge.to;
    State st = state[v];

    if (st == BOTH) {
      taken_edges.push_back(edge.ind);
      if (d[v] != -1) {
        d[v] ^= 1;
      }
      break;
    }
  }

  end: ;

  for (auto& edge : children[node]) {
    int v = edge.to;
    chooseEdges(v);
  }
}

void addEdge(int u, int v, int ind) {
  Edge edge;
  edge.to = v;
  edge.ind = ind;

  adj[u].push_back(edge);
}

void addBiEdge(int u, int v, int ind) {
  addEdge(u, v, ind);
  addEdge(v, u, ind);
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
    cin >> d[i];
  }

  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;

    addBiEdge(u, v, i);
  }

  buildState(1);


  if (state[1] == ONE) {
    cout << -1;
    return 0;
  }

  chooseEdges(1);

  cout << taken_edges.size() << endl;

  sort(taken_edges.begin(), taken_edges.end());

  for (int x : taken_edges) {
    cout << x << '\n';
  }

  return 0;
}
