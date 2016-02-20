#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

struct Stage {
	short type;
	int f, s;
} stages[N];

ll length[N];
int m;

int find(ll ind) {
	int stageInd = lower_bound(length, length + m, ind) - length;
	auto &stage = stages[stageInd];
	if (stage.type == 1) return stage.f;
	return find((ind - length[stageInd - 1] - 1) % stage.f + 1);
}

int main() {
	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

	cin >> m;

	for (int i = 0; i < m; ++i) {
		ll &l = length[i];
		cin >> stages[i].type >> stages[i].f;
		if (stages[i].type == 2)
			cin >> stages[i].s, l = stages[i].f * stages[i].s;
		else
			l = 1;
		if (i)
		  l += length[i - 1];
	}

	int n;
	cin >> n;
	while (n--){
		ll ind ;
		cin >> ind ;
		cout << find(ind) << ' ';
	}

	return 0;
}
