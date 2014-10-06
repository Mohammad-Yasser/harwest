#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i], arr[i] += arr[i - 1];
    cin >> m;
    while (cin >> m)
        cout << lower_bound(arr, arr + n + 1, m) - arr << '\n';

}
