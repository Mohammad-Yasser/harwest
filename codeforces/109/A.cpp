#include <bits/stdc++.h>


using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;
const double eps=1e-9 ;

int stoi(string s) {
	stringstream ss;
	int i;
	ss << s;
	ss >> i;
	return i;
}
int btod (int x,int b)

{
	int xd=0,i=1 ;
	while (x)
		{
			xd+=(x%10)*i ;
			i*=b ;
			x/=10 ;
		}
	return xd ;
}


int main() 
{	ios_base::sync_with_stdio(0);


	int n;
	cin >> n ;
	for (int i=n/7 ; i>=0 ; --i)
	{
		if ((n-i*7)%4==0)
		{
			cout << string ((n-i*7)/4,'4') << string(i,'7') ;
			return 0 ;
		}
	}
	cout << -1 ;
















































	return 0;
}
