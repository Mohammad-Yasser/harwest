#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    int tmp, rows[n], cols[m];
    fill(rows, rows + n, 0);
    fill(cols, cols + m, 0);
    vector<int> primes;
    bool isPrime[123456];
    fill(isPrime, isPrime + 123456, 1);
    for (int i = 2; i < 123456; ++i)
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < 123456; j += i)
                isPrime[j] = 0;
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> tmp;
            tmp = *lower_bound(primes.begin(), primes.end(), tmp) - tmp;
            rows[i] += tmp;
            cols[j] += tmp;
        }
    cout << min(*min_element(rows, rows + n), *min_element(cols, cols + m));
}
