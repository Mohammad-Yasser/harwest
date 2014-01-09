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
	while (n++)
	{
		stringstream ss ;
		ss << n ;
		string s ;
		ss >> s ;
		if (!(count(s.begin(),s.end(),s[0])>1 or count(s.begin(),s.end(),s[1])>1 or
				count(s.begin(),s.end(),s[2])>1 or
				count(s.begin(),s.end(),s[3])>1))
		{cout << s ; return 0;}
	}

























































	return 0;
}
