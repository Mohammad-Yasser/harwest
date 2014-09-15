#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    bool b = 1;
    for (int i = 0; i < n - 1; ++i)
        b &= arr[i + 1] == arr[i] or arr[i + 1] > 2 * arr[i] - 1
                or arr[i] == 1 && arr[i + 1] > 2 * arr[i];
    cout << (b ? "NO" : "YES");

}
