#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, d, ans = 0;
    cin >> n >> d;
    int time[n];
    time[0] = time[n - 1] = 0;
    for (int i = 1; i < n - 1; ++i)
        cin >> time[i];

    pair<int, int> stations[n];
    for (int i = 0; i < n; ++i)
        cin >> stations[i].first >> stations[i].second;
    priority_queue<pair<long long, int> > pr;
    pr.push(make_pair(0, 0));
    bool vis[n];
    fill(vis, vis + n, 0);
    while (1) {
        pair<long long, int> f = pr.top();
        if (f.second == n - 1) {
            cout << max(-f.first, 0LL);
            return 0;
        }
        pr.pop();
        if (vis[f.second]) continue;
        vis[f.second] = 1;
        for (int i = 1; i < n; ++i)
            if (!vis[i])
              pr.push(
                make_pair(
                  -(-f.first + 1LL * d *
                    (abs(stations[i].first - stations[f.second].first)
                      + abs(stations[i].second - stations[f.second].second)) - time[i]), i));
    }
}
