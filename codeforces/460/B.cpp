#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    long long a, b, c;
    cin >> a >> b >> c;
    vector<long long> res;
    for (int i = 1; i <= 9 * 9; ++i) {
        long long ans = b * round(pow((i), a)) + c, sm = ans % 10, tt = ans;
        while (ans /= 10)
            sm += ans % 10;
        if (sm == i && tt>0 && tt<1e9)
            res.push_back(tt);
    }
    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i)
        cout << (i ? " " : "") << res[i];
}