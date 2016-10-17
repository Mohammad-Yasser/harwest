#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

int comp[N];
pair<int, int> sock[N];

unordered_map<int, queue<int>> want;

pair<int, int> assi[N];
int adapt[N];

int main() {

	ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> comp[i];
		want[comp[i]].push(i);
	}

	for (int i = 1; i <= m; ++i) {
		cin >> sock[i].first;
		sock[i].second = i;
	}

	sort(sock + 1, sock + m + 1);

	for (int i = 1; i <= m; ++i) {
		int curr = sock[i].first;
		int cost = 0;
		while (true) {
			auto want_it = want.find(curr);
			if (want_it != want.end()) {
				auto &curr_want = want[curr];
				if (!curr_want.empty()) {
					assi[curr_want.front()] = {cost , sock[i].second};
					curr_want.pop();
					break;
				}
			}
			if (curr == 1) break;
			curr = (curr + 1) >> 1;
			++cost;
		}
	}

	int c = 0, u = 0;

	for (int i = 1; i <= n; ++i)
		if (assi[i].second != 0) {
			++c;
			u += assi[i].first;
			adapt[assi[i].second] = assi[i].first;
		}

	cout << c << ' ' << u << '\n';

	for (int i = 1; i <= m; ++i) {
		cout << adapt[i] << ' ';
	}
	cout << '\n';

	for (int i = 1; i <= n; ++i) {
		cout << assi[i].second << ' ';
	}

}
