#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

const double eps = 1e-9;

ull t(string s) {
	stringstream ss;
	ss << s;
	ull i;
	ss >> i;
	return i;
}


int main() {
	ios_base::sync_with_stdio(0);
	string a;
	int b, n;
	cin >> a >> b >> n;
	while (n--) {
		for (char i = '0'; i <= '9'; ++i)
			if (t(a + i) % b == 0) {
				a += i;
				goto r;
			}

		cout << -1;
		return 0;
		r:if (a[a.size()-1]=='0') break ;
	}
	cout << a ;
	if(n>0) cout << string(n,'0');


	return 0;
}
