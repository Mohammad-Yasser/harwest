#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    int arr[5] = { 0, 1, 2, 3, 4 };
    int g[5][5];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; cin >> g[i][j], ++j)
            ;
    int mx = 0;
    do {

        mx = max(mx,
                g[arr[0]][arr[1]] + g[arr[1]][arr[0]] + 2 * g[arr[2]][arr[3]]
                        + 2 * g[arr[3]][arr[2]] + g[arr[1]][arr[2]]
                        + g[arr[2]][arr[1]] + 2 * g[arr[3]][arr[4]]
                        + 2 * g[arr[4]][arr[3]]);

    } while (next_permutation(arr, arr + 5));
    cout << mx ;
}
