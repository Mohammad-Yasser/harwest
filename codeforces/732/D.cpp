#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;

int prep[N];
int day[N];
int exam[N];
int act[N];
int n, m;

bool can(int v) {
	memset(exam, 0, sizeof exam);

	for (int i = 1; i <= v; ++i) {
		exam[day[i]] = i;
		act[i] = 0;
	}

	for (int i = 1; i <= m; ++i) {
		if (exam[i] == 0) return false;
		act[exam[i]] = i;
	}

	int free = 0;

	for (int i = 1; i <= v; ++i) {
		if (act[i] == 0) {
			++free;
		} else {
			if (free < prep[act[i]]) return false;
			free -= prep[act[i]];
		}
	}

	return true;

}

int main() {
	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> day[i];
	}

	for (int i = 1; i <= m; ++i) {
		cin >> prep[i];
	}

	int low = 1 , high = n , mid , ans = -1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (can(mid)) {
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	cout << ans ;
}
