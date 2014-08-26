#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    long long n;
    cin >> n >> n;
    long long arr[27];
    fill(arr, arr + 27, 0);
    char c;
    while (cin >> c)
        arr[c - 'A']++;
    sort(arr, arr + 27);
    long long ans = 0, num = 0;
    for (int i = 26; i >= 0; --i) {
        long long tmp = min(arr[i], n - num);
        num += tmp;
        ans += tmp * tmp;
    }
    cout << ans;

}
