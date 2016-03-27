#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N = 400005;

tuple<int, int, int> segments[N];
struct BIT {
	const static int SZ = (1 << (int) (log2(N) + 2));
	long long a[SZ], b[SZ];

	void add(int i, long long valA, long long valB) {
		i++;
		while (i <= SZ) {
			a[i - 1] += valA;
			b[i - 1] += valB;
			i += i & -i;
		}
	}

	long long getAcc(int i) {
		int ii = i;
		i++;
		long long res = 0;
		while (i) {
			res += a[i - 1] + b[i - 1] * ii;
			i -= i & -i;
		}
		return res;
	}

	ll get(int i) {
		if (!i) return getAcc(i);
		return getAcc(i) - getAcc(i - 1);
	}

	void addRange(int st, int en = N - 1, long long val = 1) {
		int si = en - st + 1;
		add(st, -val * (st - 1), val);
		add(en + 1, val * en, -val);
	}

} bit;
int ans[N];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	map<int, int> comp;
	for (int i = 0; i < n; ++i) {
		int f, s;
		cin >> f >> s;
		segments[i] = make_tuple(f, s, i);
		comp[f];
		comp[s];
	}
	int cmpId = 0;
	for (auto &x : comp)
		x.second = cmpId++;

	sort(segments, segments + n);
	int tmp;

	for (int i = n - 1; i >= 0; --i) {
		tmp = comp[get<1>(segments[i])];
		ans[get<2>(segments[i])] = bit.get(tmp);
		bit.addRange(tmp);
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i] << '\n';

}
