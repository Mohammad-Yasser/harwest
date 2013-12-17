#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	string q="hello" ;
	string s ; cin >> s ;
	for (int i=0 ; i < s.size() ; i++)
	{
		if (s[i]==q[0]) q.erase(0,1) ;
	}
	if (q.size()) cout << "NO" ;
	else cout << "YES" ;
	return 0;
}
