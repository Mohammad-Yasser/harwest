#include <bits/stdc++.h>
using namespace std;

int main() {

    int n ;
    cin >> n ;
    vector <int> pw2;
    for (int i=0;i<=n;++i)
        pw2.push_back(i*i) ;
    int ans=0 ;
    for (int i=1;i<=n;++i)
        for (int j=i;j<=n;++j)
            ans+=binary_search(pw2.begin()+j+1,pw2.end(),pw2[i]+pw2[j]) ;
    cout << ans ;
}
