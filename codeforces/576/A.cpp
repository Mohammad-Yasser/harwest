#include <bits/stdc++.h>
using namespace std;

bool isPrime[1003];

void sieve() {
	fill(isPrime, isPrime + 1003, 1);
	for (int i = 2; i < 1003; ++i)
		if (isPrime[i])
		  for (int j = 2 * i; j < 1003; j += i)
			  isPrime[j] = 0;

}

int main() {

	sieve();
	int n;
	cin >> n;

	vector<int> ans;

	for (int i = 2; i <= n; ++i)
		if (isPrime[i]) {
			int tmp = i;
			while (tmp <= n)
				ans.push_back(tmp), tmp *= i;
		}

	cout << ans.size() << endl ;

	for (auto i : ans)
		cout << i << ' ';

}
