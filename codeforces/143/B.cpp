#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin >> s;
    int i = 0, fd = s.find('.'),md=0;
    if (s[0] == '-') {
        cout << '(';
        i++;
        md=1 ;
    }
    if (fd==-1) fd=s.size() ;
    cout <<'$';
    for (; i < fd; ((fd - i) % 3 or i==md? cout << s[i++] : cout << ',' << s[i++]))
        ;
    cout << '.' ;
    ++fd ;
    if (fd<(int)s.size()) cout << s[fd++] ;
        else cout << 0 ;
    if (fd<(int)s.size()) cout << s[fd++] ;
        else cout << 0 ;
    if (s[0] == '-')cout << ')' ;
}
