//============================================================================
// Name        : 75A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int str (int x)
{
	stringstream ss ;string s;
	ss << x ; ss >> s ;
	 s.erase(remove(s.begin(), s.end(), '0'), s.end());
	 ss.clear() ;
	 ss << s ; ss >> x ;
	 return x ;
}

int main() {
	int x,y,c ; cin >> x >> y ; c=x+y ;
	if (str(x)+str(y)==str(c)) cout << "YES" ;
	else cout << "NO" ;


}
