#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int d, smtime;
    cin >> d >> smtime;
    int arr[d][2], ans[d];
    for (int i = 0; i < d; cin >> arr[i][0] >> arr[i][1], ++i)
        ;
    for (int i = 0; i < d; ans[i] = arr[i][0], smtime -= ans[i], ++i)
        ;
    if (smtime < 0)
        goto r;
    for (int i = 0; i < d && smtime >= 0; ++i)
        ans[i] += min(arr[i][1] - arr[i][0], smtime), smtime -= min(
                arr[i][1] - arr[i][0], smtime);
    if (smtime > 0) {
        r: cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < d; cout << ans[i] << ' ', ++i)
        ;

}
