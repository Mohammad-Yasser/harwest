#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0) ;
    long long n, x,ans=0;
    cin >> n >> x;
    vector <long long> arr (n) ;
    for (int i=0;i<n;cin>>arr[i++]) ;
    sort(arr.begin(),arr.end()) ;
    for (int i = 0; i < n; x = max(x - 1, 1LL), ++i)
        ans += x * arr[i];
    cout << ans ;

}
