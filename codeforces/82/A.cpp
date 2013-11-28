//============================================================================
// Name        : 82A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n; cin >> n ;
	string s[5]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"} ;
	int x=(int)(n-1-5*(pow(2,(int)((log(n/5+(bool)(n%5)))
			/log(2)))-1)) / pow(2,((int)((int)((log(n/5+(bool)(n%5)))/log(2))+1)-1)) ;
	cout << s[x] ;


}


// / pow(2,((int)(log(n/5)+(bool)(n%5)
// /log(2)))-1)+1
