#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

map <string,vector<string> > s ;


typedef long long ll;
typedef unsigned long long ull;


void q(string w)
{
	for (int i=0 ; i<s[w].size() ; i++)
		cout << s[w][i] << endl ;
}

int main() {

	int n ;
	cin >> n ;
	for (int i=0 ; i<n ; i++)
	{
		string x,y ;
		cin >> x >> y ;
		if (y=="child") y="woman" ;
		s[y].push_back(x) ;
	}
	q("rat") ;
	q("woman") ;
	q("man") ;
	q("captain") ;
	
	return 0;
}
