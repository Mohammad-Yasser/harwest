//============================================================================
// Name        : 112A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string s1,s2 ; cin >> s1 >> s2 ;
	for (int i =0 ; i<s1.size() ; i++)
	{
		if(s1[i]<92)	s1[i]+=32 ;
		if(s2[i]<92)	s2[i]+=32 ;
		if (s1[i]<s2[i])	{cout << -1 ; return 0 ;}
		if (s2[i]<s1[i])	{cout << 1 ; return 0 ;}
	}
	cout << 0 ;

}
