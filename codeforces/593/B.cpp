#include <bits/stdc++.h> 
using namespace std;

#define sz(v) (int)(v.size())

const int N = 100005;

int k[N], b[N];

long long x1, x2;

bool srt(int i, int j) {
	if (k[i] * x1 + b[i] == k[j] * x1 + b[j]) return k[i] * x2 + b[i] < k[j] * x2 + b[j];
	return k[i] * x1 + b[i] < k[j] * x1 + b[j];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	cin >> x1 >> x2;

	for (int i = 0; i < n; ++i)
		cin >> k[i] >> b[i];

	vector<int> v1(n), v2(n);
	for (int i = 0; i < n; ++i)
		v1[i] = v2[i] = i;

	sort(v1.begin(), v1.end(), srt);

	swap(x1, x2);
	sort(v2.begin(), v2.end(), srt);

	cout << (v1 == v2 ? "NO" : "YES");

}
