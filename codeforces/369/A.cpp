//============================================================================
// Name        : 169A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,x,y ; cin >> n >> x >> y ;
	int a,b=0 ;
	for (int i=0 ; i < n ; i++)
	{
		cin >> a ;
		if (a==1) {if (x<=0) b++ ; else x-- ;}
		else {if (y>0) y-- ; else if (x>0) x-- ; else b++;}
	}
	cout << b ;
}
