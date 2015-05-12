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
    for (int i = n - 1; i >= 0; --i) {
        for (int b = B; b >= 0; --b) {
            for (int m = M; m >= 0; --m) {
                int &res = memo[i % 2][b][m];
                if (m == M) {
                    res = 1;
                    continue;
                }
                res = memo[(i + 1) % 2][b][m];
                if (b + a[i] <= B)
                  (res += memo[i % 2][b + a[i]][m + 1]) %= md;
            }
        }
    }
    cout << memo[0][0][0];

}
