#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; cin >> arr[i++])
        ;
    vector<int> x(n + 1), y(n + 1);
    x[0] = y[0] = 0;
    for (int i = 0; i < n; ++i)
        x[i + 1] = x[i] + arr[i], y[i + 1] = y[i] + (i % 2 ? -arr[i] : arr[i]);
    int mxy = *max_element(y.begin(), y.end()), mny = *min_element(y.begin(),
            y.end());
    vector<string> ans(mxy - mny);
    for (int i = 0; i < mxy - mny; ans[i] = string(x[n], ' '), ++i)
        ;
    for (int i = 0; i <= n; y[i] = mxy - y[i], ++i)
        ;
//  for (int i = 0; i <= n; cout << x[i] << ' ' << y[i] << endl, ++i)
//      ;
//  cout << endl;
    for (int i = 0; i < n; ++i) {
        while (y[i + 1] > y[i])
            ans[y[i]][x[i]] = 92, ++x[i], ++y[i];
        while (y[i] > y[i + 1])
            ans[y[i]-1][x[i]] = '/', ++x[i], --y[i];
//      for (int ind = 0; ind < ans.size(); cout << ans[ind] << endl, ++ind)
//              ;

    }
    for (int i = 0; i < ans.size(); cout << ans[i] << endl, ++i)
        ;

}
