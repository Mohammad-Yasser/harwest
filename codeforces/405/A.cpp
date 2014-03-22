#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;



int main() {
	ios::sync_with_stdio(0) ;
	int n ;
	cin >> n ;
	int a[n] ;
	for (int i=0;i<n;cin>>a[i],++i) ;
	sort(a,a+n) ;
	for (int i=0;i<n;cout<<a[i]<<' ',++i) ;


}
