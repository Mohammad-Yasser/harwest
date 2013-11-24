//============================================================================
// Name        : 366A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,a[4],b[4],c[4],d[4] ; cin >> n ;
	for (int i=0 ; i<4;i++) {cin >> a[i] >> b[i] >> c[i]>> d[i] ;}
	for (int i=0 ; i<4;i++)
	{
		if (a[i]+c[i]<=n) {cout << i+1 << " " << a[i]+n-(a[i]+c[i]) <<" " << c[i] ; return 0;}
		if (a[i]+d[i]<=n) {cout << i+1 << " " << a[i]+n-(a[i]+d[i]) <<" " << d[i] ; return 0;}
		if (b[i]+c[i]<=n) {cout << i+1 << " " << b[i]+n-(b[i]+c[i]) <<" " << c[i] ; return 0;}
		if (b[i]+d[i]<=n) {cout << i+1 << " " << b[i]+n-(b[i]+d[i]) <<" " << d[i] ; return 0;}

	}
	cout << -1 ;

}
