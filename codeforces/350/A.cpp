//============================================================================
// Name        : 350A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,m ; cin >> n >> m ;
	int a[n],b[m] ;
	for (int i=0 ; i < n ; i++) cin >> a[i] ;
	for (int i=0 ; i < m ; i++) cin >> b[i] ;
	sort(a,a+n) ;
	sort(b,b+m) ;
	n=a[n-1] ; n-- ;
	while (1)
	{	n++ ;
		if	(2*a[0]<= n && n<b[0]) {cout << n ;return 0;} if (n>=b[0]) {cout << -1 ; return 0;}}

}
