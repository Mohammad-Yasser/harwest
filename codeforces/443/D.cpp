#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double arr[n], bar[n];
    for (int i = 0; i < n; cin >> arr[i++])
        ;
    sort(arr, arr + n);
    double ans = arr[n - 1];
    bar[n - 1] = (1 - arr[n - 1]);
    for (int i = n - 2; i >= 0; bar[i] = (1 - arr[i]) * bar[i + 1], --i)
        ;
    for (int i = n - 2;
            i >= 0 && ans * (1 - arr[i]) + arr[i] * bar[i + 1] > ans;
            ans = ans * (1 - arr[i]) + arr[i] * bar[i + 1], --i)
        ;
    cout << fixed << setprecision(11) << ans;

}
// 0.1 0.2 0.3 0.4 0.5
