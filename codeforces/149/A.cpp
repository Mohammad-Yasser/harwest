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
	
	int k;
	cin >> k ;
	int y[12] ;
	for (int i = 0; i < 12;cin >> y[i], i++) ;
	sort(y,y+12,greater<int>()) ;
	int i=0,s=0 ;
	for (;i<12 && s<k ;s+=y[i],++i ) ;
	cout << (s<k ? -1 : i) ;


























































	return 0;
}
