#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cin >> n ;
    int arr[n] ;
    for (int i=0;i<n;++i)
        cin >> arr[i],arr[i]*=arr[i] ;
    sort(arr,arr+n) ;
    int ans = (n%2)*arr[0] ;
    for (int i=n-1;i>0;i-=2)
        ans+=arr[i]-arr[i-1] ;
    cout << setprecision(13) << ans *  acos(-1) ;

}
