#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    int a[6] = { 1, 2, 3, 4, 6, 12 };
    string s;
    cin >> t;
    bool b[6]={0,0,0,0,0,0} ;
    while (t--) {
        fill (b,b+6,0) ;
        cin >> s;
        for (int i = 0; i < 6; ++i) {
            for (int q = 0; q < 12 / a[i]; ++q) {
                int j = q;
                for (; j < 12 && s[j] == 'X'; j += 12/a[i])
                    ;
                if (j>11) b[i]=1 ;
            }
        }
        cout << count (b,b+6,1) << ' ' ;
        for (int i=0;i<6;++i)
            if (b[i]) cout << a[i] << 'x' << 12/a[i] << ' ' ;
        cout << endl ;
    }

}
