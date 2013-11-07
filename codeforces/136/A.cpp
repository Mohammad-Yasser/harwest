//============================================================================
// Name        : 136A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,c ; cin >> n ;
	int x[n] ;
	for (int i=0 ; i<n ; i++)
	{
		cin >> c ;
		x[c-1]=i+1 ;
	}
	for (int i=0 ; i<n ; i++)	cout << x[i] << " " ;

}
