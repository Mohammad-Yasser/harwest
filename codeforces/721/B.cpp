#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<string> passwords(n);
	for (int i = 0; i < n; ++i)
		cin >> passwords[i];
	string correct;
	cin >> correct;
	int less = 0, equal = -1;

	for (auto s : passwords) {
		if (s.size() < correct.size()) ++less;
		if (s.size() == correct.size()) ++equal;
	}

	cout << less + less / k * 5 + 1 << ' ';
	less += equal;
	cout << less + less / k * 5 + 1;

}
