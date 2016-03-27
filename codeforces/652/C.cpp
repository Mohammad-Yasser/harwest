#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N = 300005;

int p[N];

pair<int, int> a[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		p[tmp] = i;
	}

	for (int i = 0; i < m; ++i) {
		int f, s;
		cin >> f >> s;
		if (p[f] > p[s]) swap(f, s);
		a[i] = {p[f],p[s]};
	}

	sort(a, a + m);

	deque<int> dq;
	for (int i = 0; i < m; ++i) {
		while (dq.size() && a[dq.front()].second >= a[i].second)
			dq.pop_front();
		dq.push_front(i);
	}

	int lstY = -1;
	int lstX = -1;
	ll ans = 1LL * n * (n + 1) / 2;
	while (!dq.empty()) {
		int curr = dq.back() ;
		dq.pop_back();
		lstY = a[curr].second;
		ans -= 1LL * (a[curr].first - lstX) * (n - lstY);
		lstX = a[curr].first;
	}

	cout << ans;
}
