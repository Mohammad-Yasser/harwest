#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10 * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int weight[300005];

struct adjListElem {
    int v, w, idx;
    adjListElem(int v, int w, int idx) :
        v(v), w(w), idx(idx) {
    }
};
vector<adjListElem> adjList[300005];

struct PQElem {
    int v;
    long long w;
    int lastEdge;
    PQElem(int v, long long w, int lastEdge) :
        v(v), w(w), lastEdge(lastEdge) {
        this->w = w;
    }
    bool operator <(PQElem other) const {
        if (w == other.w) return weight[lastEdge] > weight[other.lastEdge];
        return w > other.w;
    }
};

int lastEdge[300005];

void dijkstra(int u) {
    priority_queue<PQElem> Q;
    Q.push(PQElem(u, 0, -1));

    while (!Q.empty()) {

        PQElem curr = Q.top();
        Q.pop();

        if (lastEdge[curr.v]) continue;
        lastEdge[curr.v] = curr.lastEdge;

        for (int i = 0; i < adjList[curr.v].size(); ++i)
            if (!lastEdge[adjList[curr.v][i].v])
              Q.push(
                PQElem(adjList[curr.v][i].v, curr.w + adjList[curr.v][i].w, adjList[curr.v][i].idx));
    }
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n = read(), m = read();

    for (int i = 1; i <= m; ++i) {
        int ui = read(), vi = read(), wi = read();
        adjList[ui].push_back(adjListElem(vi, wi, i));
        adjList[vi].push_back(adjListElem(ui, wi, i));
        weight[i] = wi;
    }

    int u = read();

    dijkstra(u);

    long long ans = 0;

    for (int i = 1; i <= n; ++i)
        if (i != u)
          ans += weight[lastEdge[i]];

    cout << ans << '\n';
    for (int i = 1; i <= n; ++i)
        if (i != u) cout << lastEdge[i] << ' ';
}
