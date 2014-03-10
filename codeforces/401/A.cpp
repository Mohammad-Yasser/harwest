#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n,x ;
    int sum=0;
    cin >> n >> x ;
    while (cin >> n) sum+=n ;
    sum=abs(sum) ;
    cout << sum/x + bool(sum%x) ;
}
