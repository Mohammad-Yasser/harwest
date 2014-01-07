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

	int n, m;
	cin >> n >> m;
	while (n++)
	{
		int i ;
		for (i=2 ; i<=sqrt(n); i++)
			if (!(n%i)) goto r;
		break ;
		r: ;
	}
	cout << (n==m ? "YES" : "NO") ;
	return 0;
}
