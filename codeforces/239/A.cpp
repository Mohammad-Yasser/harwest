#include <bits/stdc++.h>


using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

int main() 
{ 
	
	int y,k,n ;
	cin >> y >> k >> n ;
	for (int i=k-(y%k); i<=n-y ; i+=k)
		cout << i << " " ;
	if (k-(y%k)>n-y) cout << -1 ;


























































	return 0;
}
