#include <bits/stdc++.h>


using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;


const double eps=1e-9 ;
int main() 
{	ios_base::sync_with_stdio(0);

	int n;
	cin >> n ;
	int a[--n] ;
	for(int i=0;i<n;cin>>a[i++]) ;
	int q,w;
	cin >> q >> w ;
	int s=0;
	for(q--,w--;q<w;s+=a[q++]) ;
	cout << s ;
















































	return 0;
}
