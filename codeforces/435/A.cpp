#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, bs = 1, tmp = 0;
    cin >> n >> m;
    while (cin >> n) {
        if (tmp + n <= m)
            tmp += n;
        else
            tmp = n, bs++;
    }
    cout << bs ;
}
