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
	
	int n,c=0 ;
	cin >> n ;
	string s ;
	cin >> s ;
	for (int i=n ; i<s.size() ; i+=n)
	{
		if (s[i-1]==s[i-2] && s[i-1]==s[i-3])
		++c ;
	}
	cout << c ;




































































	return 0;
}
