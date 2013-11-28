//============================================================================
// Name        : 270A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int t ; cin >> t ;
	while (t--)
	{
		int x ; cin >> x ;
		cout << ((360%(180-x)==0) ? "YES" : "NO") << endl ;
	}
}
