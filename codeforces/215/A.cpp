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

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; cin >> a[i], ++i)
		;
	int m ;
	cin >> m;
	int b[m];
	for (int i = 0; i < m; cin >> b[i], ++i)
		;
	int mx =0 , mxn=0 ;
	for (int i=0 ; i < n ; ++i)
	{
		for (int ii = 0; ii < m; ++ii) {
			if (b[ii]%a[i]==0)
			{
			if (b[ii]/a[i]==mx) mxn++ ;
			if (b[ii]/a[i]>mx) mx=b[ii]/a[i] , mxn=1 ;
			}
		}
	}
	cout << mxn ;

	return 0;
}
