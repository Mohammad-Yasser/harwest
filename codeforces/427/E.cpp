#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    long long n, m, ind;
    cin >> n >> m;
    long long arr[n] ;
    for (int i=0;i<n;cin>>arr[i++]) ;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (n == 2) {
        cout << 2 * (arr[1] - arr[0]) << endl;
        return 0;
    }

    ind = n / 2;
    long long ans1 = 0;
    int i = 0;
    for (; i < ind; i += m)
        ans1 += arr[ind] - arr[i];
    for (i = n - 1; i > ind; i -= m)
        ans1 += arr[i] - arr[ind];
    long long ans2 = 0;
    i = 0;
    --ind;
    for (; i < ind; i += m)
        ans2 += arr[ind] - arr[i];
    for (i = n - 1; i > ind; i -= m)
        ans2 += arr[i] - arr[ind];
    cout << 2 * min(ans1, ans2);
}
