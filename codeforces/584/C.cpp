#include <bits/stdc++.h> 
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	string s[2] ;
	cin >> s[0] >> s[1];

	string s3 = string(n, '0');

	int cnt = n - t;
	for (int i = 0; i < n && cnt; ++i)
		if (s[0][i] == s[1][i]) s3[i] = s[0][i], --cnt;

	int ind = 0;
	while (cnt--) {
		for (int i = 0; i < 2; ++i) {
			while (ind < n && s[0][ind] == s[1][ind])
				++ind;
			if (ind == n) {
				cout << "-1";
				return 0;
			}
			s3[ind] = s[i][ind];
			++ind;
		}
	}

	for (int i = 0; i < n; ++i)
		if (s3[i] == '0')
		  for (char c = 'a';; ++c)
			  if (s[0][i] != c && s[1][i] != c) {
				  s3[i] = c;
				  break;
			  }

	cout << s3;
}
