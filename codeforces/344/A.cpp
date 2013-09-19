//============================================================================
// Name        : 344A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n ;
	cin >> n ;
	int groups=1 ;
	int y,x ;
	cin >> y ;
		for (int i = 1 ; i<n ; i++)
	{
		cin >> x ;
		if (x!=y)
			groups ++ ;
		y=x ;

	}
		cout << groups ;
}
