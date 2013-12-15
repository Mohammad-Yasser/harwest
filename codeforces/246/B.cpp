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
	int a[n];
	double av = 0;
	for (int i = 0; i < n; cin >> a[i], av += a[i], i++)
		;
	av /= n;
	cerr << av << endl;
	if ((int) av == av)
		cout << n;
	else
		cout << n - 1;

	return 0;
}
