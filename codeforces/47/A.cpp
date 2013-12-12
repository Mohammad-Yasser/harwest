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
	int n ;
	cin >> n ;
	for (int i =1 ; i <= n ; i++)
		if (n==(i*(i+1))/2) {cout << "YES" ; return 0;}
	cout << "NO" ;
	return 0;
}
