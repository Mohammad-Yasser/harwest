#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (long long i = 0; i < n; cin >> a[i++])
        ;
    for (long long i = 0; i < m; cin >> b[i++])
        ;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<long long> bldaa(n + 1), bldbb(m + 1);
    bldaa[0] = bldbb[0] = 0;
    for (long long i = 1; i <= n; ++i)
        bldaa[i] = bldaa[i - 1] + a[i - 1];
    for (long long i = 1; i <= m; ++i)
        bldbb[i] = bldbb[i - 1] + b[i - 1];
    long long ans = LLONG_MAX, tmp, ind;
    for (long long i = 0; i < n;
            ind = lower_bound(b.begin(), b.end(), a[i]) - b.begin(), tmp =
                    ind < m ? bldbb[m] - bldbb[ind] - (m - ind) * a[i] : 0, ans =
                    min(ans, (i + 1) * a[i] - bldaa[i + 1] + tmp), ++i)
        ;
    for (long long i = 0; i < m;
            ind = lower_bound(a.begin(), a.end(), b[i]) - a.begin(), tmp = ind
                    * b[i] - bldaa[ind], ans = min(ans,
                    bldbb[m] - bldbb[i] - (m - i) * b[i] + tmp), ++i)
        ;
    cout << ans;
}
