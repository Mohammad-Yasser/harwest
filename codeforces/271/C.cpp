#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m * 3 > n)
        cout << -1;
    else
        for (int i = 0; i < n; ++i)
            if ((i / m) & 1)
                cout << m - (i % m) << ' ';
            else
                cout << ((i + !(i / m)) % m) + 1 << ' ';

}
