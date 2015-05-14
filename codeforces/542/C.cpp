#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    long long dist[n][n], f;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = 1e7;

    for (int i = 0; i < n; ++i) {
        cin >> f;
        dist[i][f - 1] = 1;

    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    long long ans[n], least = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!(dist[i][j] % dist[j][j]) && dist[i][j] < 1e7)
              ans[i] = dist[j][j], least = max(least, (i != j) * dist[i][j]);

    long long l = ans[0];
    for (int i = 1; i < n; ++i)
        l = l * ans[i] / __gcd(l, ans[i]);


    cout << (least + l - 1) / l * l;

}
