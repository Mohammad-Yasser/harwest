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
	int n, r = 0;
	cin >> n;
	bool b=0;
	int y[n],z[n] ;
	for (int i = 0; i < n; i++) cin >> y[i] >> z[i] ;
	for (int i = 0; i < n; i++,b=0) {
		for (int q=0 ; q<n ; q++)
			if (q!=i && y[i]==z[q]) b=1 ;
		if (!b) r++ ;
	}
	cout << r;
	return 0;
}
