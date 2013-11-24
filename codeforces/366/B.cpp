//============================================================================
// Name        : 366B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,k,m,ii=0,sum ; cin >> n >> k ; int a[n] ;
	for (int i=0 ; i < n ; i++) cin >> a[i] ;
	for (int i=0 ; i<k ; i++)
	{
		sum=0 ;
		for (int x=i;x<n;x+=k) sum+=a[x] ;
		if (i==0) m=sum ;
		if (m>sum) {m=sum;ii=i;}
	}
	cout << ii+1 ;
}
