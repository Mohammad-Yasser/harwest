#include <bits/stdc++.h>
using namespace std;

template<class T> inline void hash_combine(std::size_t & seed, const T & v) {
	std::hash<T> hasher;
	seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
namespace std {
template<typename S, typename T> struct hash<pair<S, T>> {
	inline size_t operator()(const pair<S, T> & v) const {
		size_t seed = 0;
		::hash_combine(seed, v.first);
		::hash_combine(seed, v.second);
		return seed;
	}
};
}

unordered_map<pair<int, int>, int> cntP;
unordered_map<int, int> cntX, cntY;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		ans += cntX[x] + cntY[y] - cntP[ { x, y }];
		++cntX[x], ++cntY[y], ++cntP[ { x, y }];
	}
	cout << ans ;


	return 0;
}
