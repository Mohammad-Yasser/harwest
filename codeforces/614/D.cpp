#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int n, a;
ll m, cf, cm;

pair<int, int> arr[100005];
ll acc[100005];

map<int, int> mp;

pair<int, int> valid(ll val) {
	ll cst = 0;

	for (int i = 0; i <= n; ++i) {
		ll rem = max(0LL, val - i * cf);

		if (!cm) {
			if (!rem) return {i,0};
			continue;
		}
		rem = (rem + cm - 1) / cm;
		auto it = mp.lower_bound(rem);
		int ind = max(it->second + (it != mp.end()), i);
//		cout << i << ' ' << rem << ' ' << ind << endl;
		if (rem <= a && cst + rem * (n - ind) - acc[ind] <= m) return {i,rem};
		cst += a - arr[i].first;
	}
	return {-1,-1};
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	cin >> n >> a >> cf >> cm >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first, arr[i].second = i;
	sort(arr, arr + n, greater<pair<int, int> >());
	for (int i = n - 1; i >= 0; --i)
		acc[i] = arr[i].first + acc[i + 1];
	for (int i = 0; i < n; ++i)
		mp[arr[i].first] = i;
	mp[0] = n;
	ll low = 0, high = 1e15, mid, ans = 0;
	pair<int, int> res, tmp;
	while (low <= high) {
		mid = (low + high) >> 1;
		tmp = valid(mid);
		if (tmp.first != -1) {
			ans = mid;
			res = tmp;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) {
		if (i < res.first)
			arr[i].first = a;
		else
			arr[i].first = max(arr[i].first, res.second);
		swap(arr[i].first, arr[i].second);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i)
		cout << arr[i].second << ' ';
}
