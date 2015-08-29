#include <bits/stdc++.h>
using namespace std;

int arr[100005], n, memo[100005];

unordered_map<int, vector<int> > pos; // <prime factor , its positions>

vector<int> factors[100005];

void factorize(int ind) {
	for (int i = 2; i <= arr[ind] / i; ++i)
		if (!(arr[ind] % i)) {

			factors[ind].push_back(i), pos[i].push_back(ind);

			while (!(arr[ind] % i))
				arr[ind] /= i;
		}

	if (arr[ind] != 1)
	  factors[ind].push_back(arr[ind]), pos[arr[ind]].push_back(ind);
}

int DP(int ind) {
	if (memo[ind]) return memo[ind];
	if (ind == n) return 0;
	int mx = 1;
	for (int i = 0; i < factors[ind].size(); ++i)
		mx = max(mx,
		  1 + DP(*upper_bound(pos[factors[ind][i]].begin(), pos[factors[ind][i]].end(), ind)));
	return memo[ind] = mx;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i], factorize(i);

	for (auto &x : pos)
		sort(x.second.begin(), x.second.end()), x.second.push_back(n);

	int ans = 1;

	for (auto &x : pos)
		ans = max(ans, DP(x.second[0]));

	cout << ans;

}