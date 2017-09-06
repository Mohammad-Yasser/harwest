#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

const int N = 3e5 + 5;
Long c[N];
int ans[N];

int main() {
#ifdef Local
    freopen("test.in", "r", stdin);
#endif

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    set<pair<int, int>> st;
    Long res = 0;
    for (int i = 1; i <= k + n; ++i) {
        if (i <= n) {
            st.emplace(c[i], i);
        }
        if (i <= k) {
            continue;
        }
        auto largest = *st.rbegin();
        st.erase(largest);

        ans[largest.second] = i;
        res += 1LL * largest.first * (i - largest.second);
    }


    cout << res << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }


}