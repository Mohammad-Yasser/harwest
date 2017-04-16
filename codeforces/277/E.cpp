#include <bits/stdc++.h>
using namespace std;

const int N = 404;
typedef double CostType;

struct Edge {
  int from, to, nxt, cap;
  CostType cost;
};

struct MinCostMaxFlow {

  static constexpr int N = 2 * ::N + 2, M = N * (N - 1);
  static constexpr int kInfFlow = 1e3;
  static constexpr CostType kInfCost = 1e15;
  static constexpr int SRC = N - 1, SNK = SRC - 1;

  int head[N];
  Edge edges[M];
  int edgeCnt;

  void Init() {
    memset(head, -1, sizeof head);
    edgeCnt = 0;
  }

  void AddEdge(int u, int v, int cap, CostType cost) {
    edges[edgeCnt] = {u,v,head[u],cap,cost};
    head[u] = edgeCnt++;
  }

  void AddBi(int u, int v, int cap, CostType cost) {
    AddEdge(u, v, cap, cost);
    AddEdge(v, u, 0, -cost);
  }

  bool inQ[N];
  CostType dist[N];
  int flow[N], parent[N];

  pair<CostType, int> spfa() {
    queue<int> q;

    fill(dist, dist + N, kInfCost);
    memset(flow, 0, sizeof flow);
    dist[SRC] = 0, flow[SRC] = kInfFlow;
    q.push(SRC);
    inQ[SRC] = 1;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      inQ[curr] = 0;
      for (int edgeID = head[curr]; edgeID != -1; edgeID = edges[edgeID].nxt) {
        Edge &edge = edges[edgeID];
        int node = edge.to;
        if (edge.cap && dist[node] > dist[curr] + edge.cost) {
          dist[node] = dist[curr] + edge.cost;
          parent[node] = edgeID;
          flow[node] = min(flow[curr], edge.cap);
          if (!inQ[node]) inQ[node] = 1, q.push(node);
        }
      }
    }

    if (flow[SNK]) {
      for (int node = SNK; node != SRC; node = edges[parent[node]].from) {
        int edgeID = parent[node];
        edges[edgeID].cap -= flow[SNK];
        edges[edgeID ^ 1].cap += flow[SNK];
      }
    }

    return {dist[SNK],flow[SNK]};
  }

  pair<CostType, int> mcmf() {
    CostType cst = 0;
    int flow = 0;
    pair<CostType, int> cf;
    while (cf = spfa(), cf.second != 0)
    cst += cf.first * cf.second, flow += cf.second;
    return {cst,flow};
  }
};
MinCostMaxFlow network;

constexpr int MinCostMaxFlow::N, MinCostMaxFlow::M;
constexpr int MinCostMaxFlow::kInfFlow;
constexpr double MinCostMaxFlow::kInfCost;
constexpr int MinCostMaxFlow::SRC, MinCostMaxFlow::SNK;

int GetParentNode(int node) {
  return node;
}

int GetChildNode(int node) {
  return node + N;
}

pair<int, int> points[N];

double GetDist(int i, int j) {
  double dx = points[i].first - points[j].first;
  double dy = points[i].second - points[j].second;

  return sqrt(dx * dx + dy * dy);
}

int main() {

  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  network.Init();

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (points[i].second > points[j].second) {
        network.AddBi(GetParentNode(i), GetChildNode(j), 1, GetDist(i, j));
      }
    }

    network.AddBi(network.SRC, GetParentNode(i), 2, 0);
    network.AddBi(GetChildNode(i), network.SNK, 1, 0);
  }


  auto mcmf = network.mcmf();
  if (mcmf.second != n - 1) {
    cout << -1;
    return 0;
  }
  cout << fixed << setprecision(6) << mcmf.first << '\n';

  return 0;
}
