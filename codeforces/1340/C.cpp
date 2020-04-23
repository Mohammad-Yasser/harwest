#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

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

const int N = 1e4 + 5;
const int G = 1e3 + 5;
vector<int> islands;

struct State {
  int island;
  int green;
  int dist;

  bool operator<(const State& other) const {
    return to_tuple() > other.to_tuple();
  }
  tuple<int, int, int> to_tuple() const {
    return make_tuple(dist, green, island);
  }
};

int g, r;

int dist[N][G];
bool vis[N][G];

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  State initial;
  initial.island = 0, initial.green = g, initial.dist = 0;
  dist[0][g] = 0;
  priority_queue<State> pq;
  pq.emplace(initial);

  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();
    if (vis[curr.island][curr.green]) continue;
    vis[curr.island][curr.green] = true;
    if (curr.island + 1 == islands.size()) return curr.dist;
    State nxt;
    if (curr.green == 0) {
      nxt = curr;
      nxt.green = g;
      nxt.dist += r;
      if (dist[nxt.island][nxt.green] <= nxt.dist) continue;
      dist[nxt.island][nxt.green] = nxt.dist;
      pq.emplace(nxt);
    } else {
      for (nxt.island = curr.island - 1; nxt.island <= curr.island + 1;
           nxt.island += 2) {
        if (nxt.island < 0 || nxt.island >= islands.size()) continue;
        nxt.green =
            curr.green - abs(islands[curr.island] - islands[nxt.island]);
        nxt.dist = curr.dist + abs(islands[curr.island] - islands[nxt.island]);
        if (nxt.green < 0) continue;
        if (dist[nxt.island][nxt.green] <= nxt.dist) continue;
        dist[nxt.island][nxt.green] = nxt.dist;
        pq.emplace(nxt);
      }
    }
  }

  return -1;
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
  islands.resize(m);
  for (int& x : islands) {
    cin >> x;
  }
  sort(islands.begin(), islands.end());
  cin >> g >> r;
  cout << dijkstra() << endl;
  return 0;
}
