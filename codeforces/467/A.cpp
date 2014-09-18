#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,ans=0 ;
    cin >> n ;
    while (cin >> n >> m)
        ans+=(m-n>=2) ;
    cout << ans ;

}
