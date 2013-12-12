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
	int n, k;
	cin >> n >> k;
	int i =1 ;
	while (i++ && k%n==0 && (k/=n));
	if (k==1) cout << "YES" << endl << i-3 ;
	else cout << "NO" ;
	return 0;
}
