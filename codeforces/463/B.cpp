#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    long long lst = 0, curr, ener = 0, mx = 0;
    cin >> curr;
    while (cin >> curr) {
        ener += lst - curr;
        if (ener < 0) {
            mx += (-1 * ener);
            ener = 0;
        }
        lst = curr;
    }
    cout << mx;
}
