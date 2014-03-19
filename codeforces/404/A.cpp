#include <bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string c[n + 1];
    for (int i = 0; i < n; cin >> c[i], ++i)
        ;
    char a = c[0][0], b = c[0][1];
    if (a == b) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (((i == j or i == n - j - 1) && c[i][j] != a)
                    or (!(i == j or i == n - j - 1) && c[i][j] != b)) {
                cout << "NO";
                return 0;
            }
        }
    cout << "YES";

}
