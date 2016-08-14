#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

vector<pair<int, vector<int> >> pos[10];
vector<int> curr_vec(6);

const int lucky[3] = { 0, 4, 7 };

void gen(int ind, int curr_sum) {
	if (ind == 6) {
		pos[curr_sum % 10].push_back( { curr_sum, curr_vec });
		return;
	}

	for (int i = 0; i < 3; ++i) {
		curr_vec[ind] = lucky[i];
		gen(ind + 1, curr_sum + lucky[i]);
	}

}

ll n;
int vis[19][5], vis_id;
int col_n[19];

inline void decompose() {
	int curr_col = 0;
	memset(col_n, 0, sizeof col_n);
	while (n) {
		col_n[curr_col++] = n % 10;
		n /= 10;
	}
}
vector<int> ans[19];

bool solve(int curr_col, int carry) {
	if (curr_col == 19) return !carry;

	if (vis[curr_col][carry] == vis_id) return 0;
	vis[curr_col][carry] = vis_id;

	auto& wanted = pos[(10 + col_n[curr_col] - carry) % 10];
	for (auto& p : wanted)
		if (solve(curr_col + 1, (p.first + carry) / 10)) {
			ans[curr_col] = p.second;
			return 1;
		}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	gen(0, 0);

	int t;
	cin >> t;
	while (t--) {
		++vis_id;
		cin >> n;
		decompose();

		if (solve(0, 0)) {
			ll res[6];
			for (int i = 0; i < 6; ++i) {
				res[i] = 0;
				for (int j = 18; j >= 0; --j) {
					res[i] = 10 * res[i] + ans[j][i];
				}
				cout << res[i] << ' ';
			}
			cout << '\n';
		} else {
			cout << "-1\n";
		}
	}

}
