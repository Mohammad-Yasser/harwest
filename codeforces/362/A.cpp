//============================================================================
// Name        : 362A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int co[2][2] ; int o=0 ;
char c[8][8] ;

int main() {
	int t ; cin >> t ;
	while (t--)
	{
		o=0 ;
		for (int i=0 ; i<8 ; i++)  for (int r=0;r<8 ; r++)
		{cin >> c[i][r] ;
		if (c[i][r]=='K') {co[o][0]=i ; co[o][1]=r ; o++ ;} }

		if (sqrt(pow(co[0][0]-co[1][0],2)) == sqrt(pow(co[0][1]-co[1][1],2)) &&
//				(sqrt(pow(co[0][0]-co[1][0],2))==2 or
						sqrt(pow(co[0][0]-co[1][0],2))==4 or
						(sqrt(pow(co[0][0]-co[1][0],2)) * sqrt(pow(co[0][1]-co[1][1],2))==0 &&
								max(sqrt(pow(co[0][0]-co[1][0],2)),sqrt(pow(co[0][1]-co[1][1],2)))==4)) cout << "YES" << endl ;
		else 		cout << "NO" << endl ;

	}

}
