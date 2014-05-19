#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ul = 0, ll = 0, lr = 0,ur = 0;
    for (int i = 0; i < s.size(); ur += isupper(s[i]), lr += islower(s[i]), ++i)
        ;
    int mn=ur ;
    for (int i=0;i<s.size();++i)
    {
        if (isupper(s[i])) ul++,ur-- ;
        else ll++,lr-- ;
        mn=min(mn,ll+ur) ;
    }
    cout << mn ;
}
