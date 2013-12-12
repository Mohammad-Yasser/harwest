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
	string x,y ;
	cin >> x >> y ;
	if (x==string(y.rbegin(),y.rend())) puts("YES") ;
	else puts("NO") ;
	return 0;
}
