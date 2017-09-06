#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

const int N = 1e6 + 5;

Long min_arrival[N];
int cnt_arrival[N];

Long min_departure[N];
int cnt_departure[N];

struct Trip {
    int from, to;
    int cost;
};

vector<Trip> trips[N];

void buildArrivals() {
    vector<int> curr_min(N, INT_MAX);

    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            cnt_arrival[i] = cnt_arrival[i - 1];
            min_arrival[i] = min_arrival[i - 1];
        }
        for (auto &trip : trips[i]) {
            if (trip.from == 0) continue;
            if (curr_min[trip.from] == INT_MAX) {
                ++cnt_arrival[i];
            }

            if (trip.cost < curr_min[trip.from]) {
                if (curr_min[trip.from] != INT_MAX) {
                    min_arrival[i] -= curr_min[trip.from];
                }
                curr_min[trip.from] = trip.cost;
                min_arrival[i] += trip.cost;
            }
        }
    }
}

void buildDept() {
    vector<int> curr_min(N, INT_MAX);

    for (int i = N - 1; i >= 0; --i) {
        if (i + 1 < N) {
            cnt_departure[i] = cnt_departure[i + 1];
            min_departure[i] = min_departure[i + 1];
        }
        for (auto &trip : trips[i]) {
            if (trip.to == 0) continue;
            if (curr_min[trip.to] == INT_MAX) {
                ++cnt_departure[i];
            }

            if (trip.cost < curr_min[trip.to]) {
                if (curr_min[trip.to] != INT_MAX) {
                    min_departure[i] -= curr_min[trip.to];
                }
                curr_min[trip.to] = trip.cost;
                min_departure[i] += trip.cost;
            }
        }
    }
}

int main() {
#ifdef Local
    freopen("test.in", "r", stdin);
#endif

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    while (m--) {
        int d, f, t, c;
        cin >> d >> f >> t >> c;
        trips[d].push_back({f, t, c});
    }

    buildArrivals();
    buildDept();


    Long res = LLONG_MAX;

    for (int i = 0; i + k + 1 < N; ++i) {
        int j = i + k + 1;

        if (cnt_arrival[i] != n) continue;
        if (cnt_departure[j] != n) continue;

        res = min(res, min_arrival[i] + min_departure[j]);
    }

    if (res == LLONG_MAX) res = -1;

    cout << res;

}