#include <bits/stdc++.h>
using namespace std;

const int N = 51, M = 50 * 49;

int to[M], head[N], nxt[M], edgeCount;

bool vis[N];

void init() {
    edgeCount = 0;
    memset(head, -1, sizeof head);
}

void addEdge(int u, int v) {
    nxt[++edgeCount] = head[u];
    head[u] = edgeCount;
    to[edgeCount] = v;
}

void addBi(int u, int v) {
    addEdge(u, v), addEdge(v, u);
}

int dfs(int u) {
    int ans = 1;
    if (vis[u]) return 0;
    vis[u] = 1;
    for (int i = head[u]; i != -1; i = nxt[i])
        ans += dfs(to[i]);
    return ans;
}

int main() {

    init();

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        addBi(u, v);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += max(0, dfs(i) - 1);

    cout << (1LL << ans);

    return 0;
}
