#include <bits/stdc++.h>
using namespace std;

int memo[102][3003], T;

vector<int> tasks[102];

int DP(int height, int nNodes) {
    int &ret = memo[height][nNodes];
    if (ret + 1) return ret;
    if (height == T or !nNodes) return ret = 0;
    ret = DP(height + 1, min(3000, 2 * nNodes));
    for (int i = 0; i < nNodes; ++i)
        ret = max(ret, tasks[T - height][i] + DP(height + 1, min(3000, 2 * (nNodes - i - 1))));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(memo, -1, sizeof memo);
    int n;
    cin >> n >> T;
    while (n--) {
        int ti, qi;
        cin >> ti >> qi;
        tasks[ti].push_back(qi);
    }
    for (int i = 0; i < 102; ++i) {
        sort(tasks[i].rbegin(), tasks[i].rend());
        for (int j = 1; j < tasks[i].size(); ++j)
            tasks[i][j] += tasks[i][j - 1];
        int sz = tasks[i].size();
        for (int j = 0; j < 3003 - sz; ++j)
            tasks[i].push_back(0);

    }
    cout << DP(0, 1);

}
