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
	
	int x,y,a,b ;
	cin >> x >> y >> a >> b ;

	int n=0 ;
	for (int i=a ; i<=x ; ++i)
	{
		for (int q=b ; q<i && q <=y ; ++q)
			n++ ;
	}
	cout << n <<endl ;
	for (int i=a ; i<=x ; ++i)
		{
			for (int q=b ; q<i && q<=y; ++q)
				cout << i << " " << q << endl ;
		}

























































	return 0;
}
