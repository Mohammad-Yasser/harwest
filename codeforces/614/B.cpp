#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

string arr[100005];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string ans;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		int cnt0 = count(arr[i].begin(), arr[i].end(), '0');
		int cnt1 = count(arr[i].begin(), arr[i].end(), '1');
		if (cnt1 > 1 or cnt1 + cnt0 != arr[i].size())
			ans = arr[i], --i, --n;
		else {
			if (arr[i] == "0") {
				cout << 0;
				return 0;
			}
			arr[i].erase(arr[i].begin());
		}
	}
	if (!ans.size()) ans = "1";
	for (int i = 0; i < n; ++i)
		ans += arr[i];
	cout << ans;

}
