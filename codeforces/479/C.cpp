#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> arr[n + 1];
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);
    arr[n] = arr[n - 1];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (;
                i + 1 < n && arr[i].second <= arr[i + 1].second
                        && arr[i + 1].second >= ans; ++i)
            ;
        if (i + 1 < n)
            ans = max(ans, arr[i + 1].first);
        else
            ans = max(ans, arr[i].second);
    }
    cout << ans;
}
