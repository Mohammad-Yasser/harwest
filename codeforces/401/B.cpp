#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int x,k,a,in,mn=0,mx=0 ;
    cin >> x >> k ;
    bool b[4001] ;
    fill(b,b+4000,0) ;
    while (k--)
    {
        cin >> a ;
        if (a==1)
        {
            cin >> in ;
            b[in]=1 ;
            cin >> in ;
            b[in]=1 ;
        }
        else
        {
            cin >> in ;
            b[in]=1 ;
        }
    }
    for (int i=1;i<x;++i)
        if (!b[i])
        {
            mn++ ;
            if (!b[i+1]) i++ ;
        }
    cout << mn << ' '<<count(b+1,b+x,0) ;
}
