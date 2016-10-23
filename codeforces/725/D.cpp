#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	--n;
	vector<pair<ll, ll>> teams(n);

	ll limak, tmp;
	cin >> limak >> tmp;

	for (int i = 0; i < n; ++i) {
		cin >> teams[i].first >> teams[i].second;
		teams[i].second = teams[i].second - teams[i].first + 1;
	}

	sort(teams.rbegin(), teams.rend());

	int best = n + 1;
	int cnt = 0;
	multiset<ll> ms;

	for (int i = 0; i < n; ++i) {

		if (teams[i].first > limak) {
			ms.insert(teams[i].second);
		}
		else {
			best = min(best, i + 1 - cnt);
			if (!ms.empty() && limak >= *ms.begin()) {
				limak -= *ms.begin();
				++cnt;
				ms.erase(ms.begin());
				--i;
			}

		}
	}

	while (!ms.empty() && limak >= *ms.begin()) {
		limak -= *ms.begin();
		++cnt;
		ms.erase(ms.begin());
	}
	best = min(best, n + 1 - cnt);

	cout << best;
	return 0;
}

