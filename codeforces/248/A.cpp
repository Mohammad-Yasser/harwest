#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, mn[4] = { 0 };
    cin >> n;
    while (cin >> n >> m)
        mn[n]++, mn[2 + m]++;
    cout << min(mn[0], mn[1]) + min(mn[2], mn[3]);

}
