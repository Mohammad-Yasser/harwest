//============================================================================
// Name        : 244A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector <int> x ;
	int n,k ; cin >> n >> k ; int a[k] ;
	for (int i=0 ; i<k ; i++) 	a[i]=0 ;
	for (int i=0 ; i<k*n ; i++)	x.push_back(i+1);
	for (int i=0 ; i<k ; i++) {cin >> a[i] ; if (find(x.begin(), x.end(), a[i]) != x.end()) x.erase (find(x.begin(), x.end(), a[i])) ;}
	for (int i=0 ; i<k ; i++)
	{
		cout << a[i] << " ";
		for (int ii=1; ii<n ; ii++)
		{
			cout << x[0] << " "; x.erase (x.begin()) ;

		}
		cout << endl ;

	}

}
