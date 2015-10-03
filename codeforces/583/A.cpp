#include <bits/stdc++.h> 
using namespace std;

bool h[51], v[51];

int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n * n; ++i) {
		int a, b;
		cin >> a >> b;
		if (!h[a] && !v[b]) {
			cout << i << endl;
			h[a] = v[b] = 1;
		}
	}

}
