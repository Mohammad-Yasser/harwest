#include <bits/stdc++.h>


using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;


const double eps=1e-9 ;
int main() 
{ios_base::sync_with_stdio(0);


int y=1<<25 ;
int n,c ;
cin >> n >> c ;
n--;
int a,b;
cin >> a ;
int mx=0;
while (n--)
{
	cin >> b;
	mx=max(mx,a-b-c) ;
	a=b;
}
if (mx>0) cout << mx;
else cout << 0;















































	return 0;
}
