#include <bits/stdc++.h>
using namespace std;
bool b[3000001];
int main() {
    ios_base::sync_with_stdio(0) ;
    fill(b, b + 3000001, 0);
    for (int i = 2; i < 3000001; ++i)
        for (int j = 2 * i; j < 3000001; b[j] = 1, j += i)
            ;
    long long ind = 3, n;
    cin >> n;
    while (n--) {
        for (; b[ind] ; ++ind)
            ;
        cout << ind++ << ' ' ;
    }

}
