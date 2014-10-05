#include <bits/stdc++.h>
using namespace std;

int main() {

    cout << "+------------------------+\n";
    int n,tt;
    cin >> n;
    tt=n ;
    string s;
    for (int l = 0; l < 4; ++l)
        for (int i = 0; i < 23; ++i) {
            if (i == 22) {
                cout << "." << ".|"[l != 2];
                if (!l)
                    cout << 'D';
                else
                    cout << '.';
                cout << '|';
                if (l == 3 or l == 0)
                    cout << ")";
                cout << '\n';
            } else {
                if ((i & 1) && (l != 2 or i == 1))
                    cout
                            << (n - (i / 2) * (3 - l - (l < 2))
                                    - (l < 2 && tt > 2) > 0 ? 'O' : '#'), n -= n
                            - (i / 2) * (3 - l - (l < 2)) - (l < 2 && tt > 2) > 0;
                else
                    cout << (i ? '.' : '|');
            }

        }
    cout << "+------------------------+\n";

}
