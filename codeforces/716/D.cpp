#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3, M = 3e4;

struct Edge {
  int nxt, from, to, cost;
} edges[M];

int curr_edge;
int head[N];
ll dist_t[N], dist_s[N];

void Init() {
  memset(head, -1, sizeof head);
  memset(dist_t, 0x3f, sizeof dist_t);
  memset(dist_s, 0x3f, sizeof dist_s);
  curr_edge = 0;
}

void AddEdge(int u, int v, int w) {
  edges[curr_edge] = {head[u], u, v, w};
  head[u] = curr_edge++;
}

void AddBiEdge(int u, int v, int w) {
  AddEdge(u, v, w);
  AddEdge(v, u, w);
}

int n, m, l, s, t;

void DijkstraT() {
  set<pair<ll, int>> q;
  q.insert({0, t});

  while (!q.empty()) {
    auto curr = *q.begin();
    q.erase(q.begin());
    if (dist_t[curr.second] < 1e17) continue;
    dist_t[curr.second] = curr.first;

    for (int e = head[curr.second]; e != -1; e = edges[e].nxt) {
      Edge edge = edges[e];
      if (dist_t[edge.to] > 1e17) {
        q.insert({curr.first + abs(edge.cost), edge.to});
      }
    }
  }
}

void DijkstraS() {
  set<pair<ll, int>> q;
  q.insert({0, s});

  while (!q.empty()) {
    auto curr = *q.begin();
    q.erase(q.begin());
    if (dist_s[curr.second] < 1e17) continue;
    dist_s[curr.second] = curr.first;

    for (int e = head[curr.second]; e != -1; e = edges[e].nxt) {
      Edge& edge = edges[e];
      if (dist_s[edge.to] > 1e17) {
        if (edge.cost < 0 &&
            curr.first + abs(edge.cost) + dist_t[edge.to] < l) {
          edge.cost = l - curr.first - dist_t[edge.to];
        }
        q.insert({curr.first + abs(edge.cost), edge.to});
      }
    }
  }
}

int main() {
  Init();

  cin >> n >> m >> l >> s >> t;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    if (w == 0) w = -1;
    AddBiEdge(u, v, w);
  }

  DijkstraT();
  DijkstraS();
  if (dist_s[t] != l) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < curr_edge; i += 2) {
    cout << edges[i].from << ' ' << edges[i].to << ' '
         << abs(max(edges[i].cost, edges[i ^ 1].cost)) << '\n';
  }

  return 0;
}
