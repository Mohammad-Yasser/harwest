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
	int n;
	cin >> n ;
	int y ;
	int a[3]={0,0,0};
	for (int i=0 ; i<n ; ++i)
		for (int t=0;t<3;++t)
			cin >> y , a[t]+=y ;
	cout << ((a[0]==a[1] && a[1]==a[2] && a[2]==0) ? "YES" : "NO") ;

























































	return 0;
}
