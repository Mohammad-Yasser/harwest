#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    long long arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    if (arr[n] % 3) {
        cout << 0;
        return 0;
    }
    vector<int> frst, sec;
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[n] / 3)
            frst.push_back(i);
        if (arr[i] == 2 * arr[n] / 3)
            sec.push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < frst.size(); ++i) {
        ans += (long long) (sec.end()
                - upper_bound(sec.begin(), sec.end(), frst[i]));
    }
    cout << ans;
}
