#include <bits/stdc++.h>

using namespace std;

int d, m, y, bb[3], mon[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30,
        31 };
int main() {
    char c;
    cin >> d >> c >> m >> c >> y >> bb[0] >> c >> bb[1] >> c >> bb[2];
    sort(bb, bb + 3);
    do {
        if (bb[1] <= 12 && bb[0] <= mon[bb[1]]
                && !(bb[0] == 29 && bb[1] == 2 && (bb[2] % 4))
                && (y - bb[2] > 18 or y - bb[2] == 18 && m > bb[1]
                        or y - bb[2] == 18 && m == bb[1] && d >= bb[0])) {
            cout << "YES";
            return 0;
        }
    } while (next_permutation(bb, bb + 3));
    cout << "NO";
}
