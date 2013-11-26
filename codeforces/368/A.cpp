//============================================================================
// Name        : 368A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,d,m,ans=0 ; cin >> n >> d ; int a[n] ; for (int i=0 ; i<n ; i++) {cin >> a[i] ;ans+=a[i] ;} cin >> m ;
	if (m>=n) cout << (n-m)*d +  ans ;
	else
		{sort(a,a+n) ; ans=0 ; for (int i=0 ; i<m ; i++) ans+=a[i] ; cout << ans ;}
}
