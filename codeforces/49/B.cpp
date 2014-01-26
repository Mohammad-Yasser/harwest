#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;
const double eps = 1e-9;

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



int main() {
	ios_base::sync_with_stdio(0);

	string x, y;
	cin >> x >> y;
	int b = max(*max_element(x.begin(), x.end()),
			*max_element(y.begin(), y.end()))-'0'+1, q = stoi(x), w = stoi(y);
	int s=btod(q,b)+btod(w,b),n=0;

	while (++n &&(s/=b));
	cout << n ;
	return 0;
}
