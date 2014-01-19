#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);

	bool b[1000000];
	fill(b,b+1000000,1) ;
	for (int i = 3; i < 1000; i += 2)
		if (b[i])
			for (int j = 3 * i; j < 1000000; b[j] = 0, j += 2 * i)
				;
	cerr << b[999983] ;
	int n;
	cin >> n;
	unsigned long long int a;

	while (cin >> a) {
		double w = sqrt(a);
		cerr << w ;
		if (a == 4) {
			cout << "YES"<<endl;
			continue;
		}
		if (a==1) goto r ;
		if (w == (int) w && int(w) % 2 && b[(int)w])
			cout << "YES";
		else
			r:cout << "NO";
		cout <<endl;
	}

	return 0;
}
