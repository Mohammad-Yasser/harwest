#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000006;
const int K = 26;
const int MOD = 1000000007;

int sum;
int cnt[K];

int last[K];
set<pair<int, int>> last_st;

int k;

void UpdateLast(int id, int pos) {
	last_st.erase( { last[id], id });
	last[id] = pos;
	last_st.insert( { last[id], id });
}

void UpdateCnt(int id) {
	sum = (sum - cnt[id]) % MOD;
	cnt[id] = (sum + cnt[id] + 1) % MOD;
	sum = (sum + cnt[id]) % MOD;
}

int GetEarliest() {
	return last_st.begin()->second;
}

void Add(int id, int pos) {
	UpdateLast(id, pos);
	UpdateCnt(id);
}

void Init() {
	for (int i = 0; i < k; ++i) {
		last_st.insert( { 0, i });
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif

	int n;
	cin >> n >> k;
	Init();
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		Add(s[i] - 'a', i + 1);
	}

	for (int i = s.size() + 1; i <= s.size() + n; ++i) {
		int tmp = GetEarliest();
		Add(tmp, i);
	}

	cout << (sum + MOD + 1) % MOD;

	return 0;
}
