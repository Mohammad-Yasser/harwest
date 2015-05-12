// Not my code, just trying to recognize why it takes much time.

// ya rab
#include <bits/stdc++.h>

using namespace std;

int n, a[505], md;
int memo[505][505][2];
int B, M;

int main() {

    ios::sync_with_stdio(false);
    cin >> n >> M >> B >> md;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int b = B; b >= 0; --b)
        memo[b][M][1] = memo[b][M][0] = 1;
    for (int i = n - 1; i >= 0; --i)
        for (int m = M - 1; m >= 0; --m)
            for (int b = B; b >= 0; --b)
                memo[b][m][i % 2] = (memo[b][m][!(i % 2)]
                  + ((b + a[i] > B) ? 0 : memo[b + a[i]][m + 1][i % 2])) % md;

    cout << memo[0][0][0];

}
