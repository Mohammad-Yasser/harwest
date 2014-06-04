#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, d;
    cin >> n >> d;
    int sm = 0, tmp;
    while (cin >> tmp)
        sm += tmp;
    if (sm + 10 * n - 10 > d)
        cout << -1;
    else
        cout << 2 * n - 2 + (d - sm - 10 * n + 10) / 5;

}
