//============================================================================
// Name        : 37A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int t,mx=1,m=1,n=0 ;
	cin >> t ;
	int x[t] ;
	for (int i=0 ; i<t ; i++) cin >> x[i] ;
	for (int i=0 ; i<t ; i++)
	{
		if (x[i]!=0)
		{
			for (int r=i+1;r<t;r++)
				if (x[i]==x[r])
				{
					m++ ; x[r]=0 ;
				}
				mx=max(mx,m) ; m=1 ;
				n++ ;
		}
	}
	cout << mx << " " << n ;

}
