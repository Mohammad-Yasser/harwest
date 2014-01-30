#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n, k, a = 0, b;
	cin >> n >> k;
	vector<unsigned long long int> x(n);
	vector <unsigned long long int> s(n - k + 1);
	for (int i = 0; i < n; cin >> x[i++])
		;
	for (int i = 0; i <= n - k; s[i] = accumulate(x.begin() + i, x.begin() + i + k,0LL), i += k)
		;
	for (int i = 1; i < k; ++i)
		for (int q = i; q <= n - k; q += k)
			s[q] = s[q - 1] - x[q - 1] + x[q + k - 1];
	vector<pair<unsigned long long int, int> > sp(n - k + 1);
	sp[n - k] = make_pair(s[n - k], n - k);
	for (int i = n - k - 1; i >= 0; i--) {
		if (s[i] >= sp[i + 1].first)
			sp[i] = make_pair(s[i], i);
		else
			sp[i] = make_pair(sp[i + 1].first,sp[i+1].second);
	}
	b = sp[k].second;
	for (int i = 0; i < n - 2 * k + 1; ++i) {
		if (s[i] + sp[i + k].first > s[a] + sp[b].first) {
			a = i;
			b = sp[i + k].second;
		}
	}

	cout << ++a << " " << ++b << endl;
//	if (n==100000)
//	{
//		cout << s[13341] << " " << s[69268] << endl
//				<< s[79449] << " " << s[89358] ;
//	}
	return 0;
}
