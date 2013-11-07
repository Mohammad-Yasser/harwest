//============================================================================
// Name        : 110A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string s,sss ; cin >> s ;
	int n=0 ;
	for (int i =0 ; i<s.size();i++)
			if ((s[i]=='4' or s[i]=='7')) n+=1 ;
	stringstream ss ;
	ss << n ; ss >> sss ;
	for (int i =0 ; i<sss.size();i++)
		if (!(sss[i]=='4' or sss[i]=='7')) {cout << "NO" ; return 0 ;}
	cout << "YES" ;
}
