#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	n *= m;
	string s = "WGB";
	while (n--) {
		char c;
		cin >> c;
		if (s.find(c) == string::npos) {
			cout << "#Color";
			return 0;
		}
	}
	cout << "#Black&White";

}
