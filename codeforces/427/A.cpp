#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    int n;
    cin >> n ;
    int ans=0,free=0 ;
    while (cin >> n)
    {
        if (n==-1)
        {
            if (free==0) ++ans ;
            else free-- ;
        }
        else
            free+=n ;
    }
    cout << ans ;


}
