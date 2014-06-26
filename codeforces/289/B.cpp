#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, d, mnn = INT_MAX;
    cin >> n >> m >> d;
    int arr[n * m];
    for (int i = 0; i < n * m; cin >> arr[i++])
        ;
    int mar = *min_element(arr, arr + n * m), mxar = *max_element(arr,
            arr + n * m);
    for (int i = mar; i <= mxar; i += d) {
        int cst = 0;
        for (int j = 0; j < n * m; ++j)
            if (abs(arr[j] - i) % d)
                goto r;
            else
                cst += abs(arr[j] - i) / d;
        mnn = min(cst, mnn);
        r: ;
    }
    if (mnn == INT_MAX)
        cout << -1;
    else
        cout << mnn;

}
