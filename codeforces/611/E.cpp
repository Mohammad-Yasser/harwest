#include <bits/stdc++.h>
using namespace std;

int n, heroes[3], pos[3], enemies[200005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("test.in", "rt", stdin);
#endif

    cin >> n >> heroes[0] >> heroes[1] >> heroes[2];
    sort(heroes, heroes + 3);

    for (int i = 0; i < n; ++i)
        cin >> enemies[i];

    multiset<int> st(enemies, enemies + n);

    if (*st.rbegin() > heroes[0] + heroes[1] + heroes[2]) {
        cout << -1;
        return 0;
    }

    int sumHeroes = accumulate(heroes, heroes + 3, 0);

    int ans = 0;

    while (st.size()) {
        int curr = *st.rbegin();

        st.erase(st.find(curr));

        if (heroes[2] >= curr) {
            bool b = 1;
            for (int i = 0; i < 2; ++i)
                if (st.size()) {
                    auto it = st.upper_bound(heroes[i]);
                    if (it != st.begin()) {
                        --it;
                        st.erase(it);
                        b = 0;
                    }
                }
            if (st.size() && b) {
                auto it = st.upper_bound(heroes[0] + heroes[1]);
                if (it != st.begin()) {
                    --it;
                    st.erase(it);
                }
            }
        }
        else {
            for (int i = 2; i >= 0; --i)
                if (st.size() && sumHeroes - heroes[i] >= curr) {
                    auto it = st.upper_bound(heroes[i]);
                    if (it != st.begin()) {
                        --it;
                        st.erase(it);
                    }
                    break;
                }
        }

        ++ans;
    }
    cout << ans;

    return 0;

}
