#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <long long> arr(n+1), srtd(n+1);
    arr[0]=srtd[0]=0 ;
    for (int i = 1; i <= n; cin >> arr[i], srtd[i] = arr[i], ++i)
        ;
    sort(srtd.begin(), srtd.end());
    for (int i = 1; i <= n; arr[i] += arr[i - 1], srtd[i] += srtd[i - 1], ++i)
        ;
    int a, b, c;
    cin >> a;
    while (cin >> a >> b >> c) {
        if (a == 1)
            cout << arr[c] - arr[b - 1];
        else
            cout << srtd[c] - srtd[b - 1];
        cout << '\n';
    }
}
