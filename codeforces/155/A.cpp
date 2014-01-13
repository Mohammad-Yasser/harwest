#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

int main() {

	int n, mx, mn, i, a = 0;
	cin >> n;
	n--;
	cin >> mx;
	mn=mx;
	while (n--) {
		cin >> i;
		if (i < mn)
			{mn=i ; a++;}
		if (i>mx)
		{mx=i ; a++;}
	}

	cout <<a;
	
}
