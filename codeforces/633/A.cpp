#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 10004; ++i)
		for (int j = 0; j < 10004; ++j)
			if (i * a + j * b == c) {
				cout << "Yes";
				return 0;
			}
	cout << "No";
}