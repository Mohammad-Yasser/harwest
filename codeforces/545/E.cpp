#include <bits/stdc++.h>
using namespace std;

long long dist[300005];

struct Edge {
    int u, v, idx;
    long long w ;
    Edge(int u, int v, long long w, int i) :
        u(u), v(v), w(w), idx(i) {
    }
    Edge() {
    }
    bool operator <(Edge other) const {
        return w < other.w;
    }
};

struct Elem {
    int v ;
    long long  w;
    Elem(int v, long long w) :
        v(v), w(w) {
    }
    bool operator <(Elem other) const {
        return w > other.w;
    }
};

vector<Elem> adjList[300005];
Edge edges[300005];

void dijkstra(int u) {
    priority_queue<Elem> Q;
    Q.push(Elem(u, 0));

    while (!Q.empty()) {

        Elem curr = Q.top();
        Q.pop();

        if (dist[curr.v]) continue;
        dist[curr.v] = curr.w;

        for (int i = 0; i < adjList[curr.v].size(); ++i)
            if (!dist[adjList[curr.v][i].v] && adjList[curr.v][i].v != u)
              Q.push(Elem(adjList[curr.v][i].v, curr.w + adjList[curr.v][i].w));
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        edges[i] = Edge(ui, vi, wi, i + 1);
        adjList[ui].push_back(Elem(vi, wi));
        adjList[vi].push_back(Elem(ui, wi));
    }

    int u;
    cin >> u;
    dijkstra(u);

    long long ans = 0;
    bool done[300005];
    fill(done, done + n + 1, 0);
    done[u] = 1;

    sort(edges, edges + m);

    for (int i = 0; i < m; ++i) {

        if ((done[edges[i].v] or dist[edges[i].u] + edges[i].w > dist[edges[i].v])
          && (done[edges[i].u] or dist[edges[i].v] + edges[i].w > dist[edges[i].u]))
            edges[i].u = -1;

        else {

            done[edges[i].v] |= (dist[edges[i].u] + edges[i].w == dist[edges[i].v]);
            done[edges[i].u] |= (dist[edges[i].v] + edges[i].w == dist[edges[i].u]);
            ans += edges[i].w;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < m; ++i)
        if (edges[i].u + 1) cout << edges[i].idx << ' ';
}
