//============================================================================
// Name        : 25A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n; cin >> n ;
	int x[n] ; cin >> x[0] >> x[1] >> x[2] ;
	if(x[0]%2==x[1]%2 && x[0]%2!=x[2]%2) {cout << 3 ; return 0;}
	if(x[2]%2==x[1]%2 && x[0]%2!=x[2]%2) {cout << 1 ; return 0;}
	if(x[2]%2==x[0]%2 && x[1]%2!=x[2]%2) {cout << 2 ; return 0;}
	for (int i=3 ; i<n ; i++)
	{
		cin >> x[i] ;
		if (x[i]%2!=x[i-1]%2 && x[i]%2!=x[i-2]%2) {cout << i+1 ; return 0;}
	}

}
