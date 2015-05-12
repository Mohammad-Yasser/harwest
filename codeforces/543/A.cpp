// Not my code, just trying to recognize why it takes much time.

// ya rab
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int n, a[505], md;
int memo[2][505][505];
int B, M;

int main() {

    ios::sync_with_stdio(false);
    cin >> n >> M >> B >> md;
    FOR (i , 0 , n)
            cin >> a[i];
    for (int b = B; b >= 0; --b)
        memo[1][b][M] = memo[0][b][M] = 1;
    for (int i = n - 1; i >= 0; --i)
        for (int b = B; b >= 0; --b)
            for (int m = M - 1; m >= 0; --m)
                memo[i % 2][b][m] = (memo[(i + 1) % 2][b][m]
                  + ((b + a[i] > B) ? 0 : memo[i % 2][b + a[i]][m + 1])) % md;

    cout << memo[0][0][0];

}
