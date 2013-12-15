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
	ull n,m,a,b ;
	cin >> n >> m >> a >>b ;
	cout << (b/((n*m)/__gcd(n,m))-(a-1)/((n*m)/__gcd(n,m))) ;
	return 0;
}
