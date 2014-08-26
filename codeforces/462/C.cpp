#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    long long n, ans = 0, tmp = 0;
    cin >> n;
    vector<long long> vec(n + 1);
    vec[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    for (int i = n - 1; i >= 0; --i)
        vec[i] += vec[i + 1];
    for (int i = 0; i < n; ++i)
        ans += vec[i];
    cout << ans;

}