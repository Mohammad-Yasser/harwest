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
	int n, s1 = 0, s2 = 0, s3 = 0;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (i % 3 == 0)
			s1 += a;
		else if (i % 3 == 1)
			s2 += a;
		else
			s3 += a;
	}
	if (max(max(s1,s2),s3)==s1) cout << "chest" ;
	else if (max(max(s1,s2),s3)==s2) cout << "biceps" ;
	else cout << "back" ;
	return 0;
}
