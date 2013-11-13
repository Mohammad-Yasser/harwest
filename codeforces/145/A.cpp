//============================================================================
// Name        : 145A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	string s1,s2 ; int c7=0 , c4=0 ;
	cin >> s1 >> s2 ;
	for(int i=0;i<s1.size();i++)
	{
		if (s1[i]!=s2[i])
		{
			if (s1[i]=='7') c7++ ;
			else c4++ ;
		}
	}
	cout << max(c7,c4) ;
}
