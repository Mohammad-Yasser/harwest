#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];

int memo[100005], cnt[100005];

int dp(int node) {
    int &ret = memo[node];
    if (ret) return ret;
    ret = 1;
    for (int &v : adj[node])
        ret = max(ret, 1 + dp(v));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("test.in", "rt", stdin);
#endif
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[max(u, v)].push_back(min(u, v));
        ++cnt[u], ++cnt[v];
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, 1LL * cnt[i] * dp(i));
    cout << ans;

    return 0;

}
