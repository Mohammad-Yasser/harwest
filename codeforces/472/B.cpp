#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i -= k)
        ans += arr[i] - 1;
    cout << 2 * ans << endl;

}