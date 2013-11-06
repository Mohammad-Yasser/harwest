//============================================================================
// Name        : 160A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,sum1=0,sum2=0 ; cin >> n ; int x[n] ;
	for (int i=0 ; i<n ; i++)	cin >> x[i] ;
	sort(x,x+n, greater<int>());
	for (int i=0 ; i<n ; i++)
	{
		sum1=0 ; sum2=0 ;
		for (int ii=0 ; ii<=i ; ii++) sum1+=x[ii] ;
		for (int ii=i+1 ; ii<n ; ii++) sum2+=x[ii] ;
		if (sum1>sum2) {cout << i+1 ; return 0 ;}
	}
}
