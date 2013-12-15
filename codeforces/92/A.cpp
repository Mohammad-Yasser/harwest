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
	int n , m,z ;
	cin >>n >> m ;
	z=m%((n+1)*n/2) ;
	for (int i=1 ; z-i>=0 ; i++) z-=i ;
	cout << z ;
	return 0;
}
