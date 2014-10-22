#include <bits/stdc++.h>

using namespace std;

int main() {

    int n ;
    cin >> n ;
    int arr[n] , arsrt[n] ;
    for (int i=0;i<n;++i)
    {
        cin >> arr[i] ;
        arsrt[i]=arr[i] ;
    }
    sort(arsrt,arsrt+n) ;
    int res = 0 ;
    for (int i=0;i<n;++i)
        res+=arsrt[i]!=arr[i] ;
    if (res>2) cout << "NO" ;
    else cout << "YES" ;
}
