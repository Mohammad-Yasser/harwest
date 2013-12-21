#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll ss(string s) {
	stringstream t;
	t << s;
	ll m;
	t >> m;
	return m;
}

int main() {
	string s;
	cin >> s;
	ll mx = -1;
	for ( int i = 0; i < signed (s.size()) - 2; i++) {
		if (ss(s.substr(0, i + 1)) > 1000000 or (s[0]=='0' && i==1))
			break;

		for ( int q = 1; q < signed (s.size()) - 1 - i; q++) {

			if (s[i + q + 1] == '0' && (i+q+1!=signed(s.size())-1))
										goto r ;
			if (ss(s.substr(i + 1, q)) > 1000000)
				break;
			if (ss(s.substr(i + q + 1, s.size() - i - q - 1)) > 1000000)
				goto r;
			mx = max(mx,
					ss(s.substr(0, i + 1)) + ss(s.substr(i + 1, q))
							+ ss(s.substr(i + q + 1, s.size() - i - q - 1)));
			r:if (s[i+1]=='0') break ;
		}
	}
	cout << mx;
	return 0;
}
