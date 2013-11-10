//============================================================================
// Name        : 210A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,k ; cin >> n >> k ;
	int t[n][n] ;
	for (int i=0 ; i<n ; i++) for (int ii=0 ; ii<n ; ii++)
		{
			if (i==ii)	t[i][i]=k ;
			else t[i][ii]=0 ;
		}

	for (int i=0 ; i<n ; i++) {for (int ii=0 ; ii<n ; ii++) {cout << t[i][ii] ; if (ii+1<n)	cout << " " ;} cout << endl ;}
}
