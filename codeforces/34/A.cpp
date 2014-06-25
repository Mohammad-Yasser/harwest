#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mni = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; cin >> arr[i++])
        ;
    for (int i = 1; i < n; ++i)
        if (abs(arr[i] - arr[i - 1]) < abs(arr[mni] - arr[(mni + n - 1) % n]))
            mni = i;
    cout << mni + 1 << ' ' << 1 + (mni + n - 1) % n;
}
