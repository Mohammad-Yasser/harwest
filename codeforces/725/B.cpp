#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string order = "fedabc";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	char c;
	cin >> n >> c;
	--n;

	n = n - (n % 4) + (n % 2);

	ll rows = n;
	ll seats = 6 * ((n + 1) / 2);
	cout << rows + seats + order.find(c) + 1;
	return 0;
}
