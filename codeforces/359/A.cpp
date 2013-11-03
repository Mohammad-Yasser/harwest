//============================================================================
// Name        : 359A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,m; cin >> n >> m ; bool b[n][m] ;
	for (int i=0 ; i<n ;i++)		for (int ii=0 ; ii<m ; ii++)
		{
		cin >> b[i][ii] ;
		if ((i==0 or ii==0 or i==n-1 or ii==m-1) && b[i][ii] ) {cout << 2 ; return 0 ;}
		}
	cout << 4 ;
}










