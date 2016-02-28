#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> get(vector<int> &a) {
	vector<int> c;
	bool oneAppeared = 0;
	for (int i = 0; c.size() < n - 1; ++i) {
		if (i == n) i = 0;
		oneAppeared |= a[i] == 1;
		if (oneAppeared && a[i]) c.push_back(a[i]);
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	vector<int> c = get(a), d = get(b);
	if (c == d)
		cout << "YES";
	else
		cout << "NO";
}
