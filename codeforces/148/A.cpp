//============================================================================
// Name        : 148A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int k,l,m,n;long int d ; cin >> k >> l >> m >> n >> d ;
	bool b[d+1] ; b[0]=0 ;
	for (int i=1 ; i<=d ; i++)
		{
		if (i%k==0 or i%l==0 or i%m==0 or i%n==0) b[i]=1 ;
		else b[i]=0 ;
		}
	cout << count(b,b+d+1,1) ;
}
