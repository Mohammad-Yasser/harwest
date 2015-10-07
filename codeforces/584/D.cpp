#include <bits/stdc++.h> 
using namespace std;

#define sz(v) ((int)v.size())

const int N = 345;

bool notPrime[N];
vector<int> primes;

void sieve() {
	for (int i = 2; i < N; ++i)
		if (!notPrime[i]) {
			primes.push_back(i);
			for (int j = i * i; j < N; j += i)
				notPrime[j] = 1;
		}
}

unordered_map<int, pair<int, int> > mp;

int main() {

	sieve();
	primes.push_back(0);

	for (int i = 0; i < sz(primes); ++i)
		for (int j = i; j < sz(primes); ++j)
			mp[primes[i] + primes[j]] = {primes[i],primes[j]};

	int n;
	cin >> n;
	int tmp = n + 1;
	bool fnd = 0;
	while (!fnd && --tmp) {
		fnd = 1;
		for (int i = 2; i * i <= tmp; ++i)
			fnd &= !!(tmp % i);
	}


	vector<int> ans;
	ans.push_back(tmp);
	auto &x = mp[n - tmp];
	if (x.first) ans.push_back(x.first);
	if (x.second) ans.push_back(x.second);
	cout << sz(ans) << endl;
	for (int i = 0; i < sz(ans); ++i)
		cout << ans[i] << ' ';

}
