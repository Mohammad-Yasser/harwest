#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(0);
    string s, s1, s2;
    cin >> s >> s;
    s1 = s2 = string(s.size(), '.');
    if (s==string(s.size(),'.'))
    {
        cout << s.size() ;
        return 0 ;
    }
    int y = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.') {
            int ir = i, il = i;
            for (; ir >= 0 && s[ir] == '.'; --ir)
                ;
            for (; il < s.size() && s[il] == '.'; ++il)
                ;
        y+=bool(il-i==i-ir && ir!=-1 && il!=s.size() or s[ir]=='L' or s[il]=='R') ;
    }
}
    cout << y ;

}
