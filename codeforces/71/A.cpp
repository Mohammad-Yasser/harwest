#include <iostream>
using namespace std;

int main() {
    string s ;
    int n ; cin >> n ;
    for (;n>0;n--)
    {
        cin >> s ;
        if (s.size()>10) cout << s[0] << s.size()-2<<s[s.size()-1] ;
        else cout << s ;
        cout << endl ;
    }
}