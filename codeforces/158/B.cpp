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
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; cin >> a[i], i++)
		;


	int c1 = count(a.begin(), a.end(), 1), c2 = count(a.begin(), a.end(), 2),
			c3 = count(a.begin(), a.end(), 3), c4 = count(a.begin(), a.end(),
					4);

cout << ((c1>c3) ? (c4 + c3 +c2/2 + (c1-c3)/4 + (((c1-c3)%4)+2*(c2%2))/4 +(bool)((((c1-c3)%4)+2*(c2%2))%4)):
		(c4 + c3 + c2/2 + c2%2)) ;
return 0;
}

