#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; cin >> s[i++])
        ;
    bool b=1 ;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int nm = 0;
            nm += (i > 0 && s[i - 1][j] == 'o') + (j > 0 && s[i][j - 1] == 'o')
                    + (j < n - 1 && s[i][j + 1] == 'o')
                    + (i < n - 1 && s[i + 1][j] == 'o');
            b&=!(nm%2) ;
        }
    cout << (b?"YES":"NO") ;

}
