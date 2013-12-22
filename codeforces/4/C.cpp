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

typedef long long ll;
typedef unsigned long long ull;

int main() {
	map <string,int> s ;
	int n ;
	cin >> n ;
	for (int i=0 ; i<n ; i++)
	{
		string x ;
		cin >> x ;
		if (s[x]) cout << x << s[x] ;
		else cout << "OK"  ;
		s[x]++ ;
		cout << endl ;
	}
	return 0;
}
