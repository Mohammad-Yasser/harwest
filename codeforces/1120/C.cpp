#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 5003;
const int SQRT = sqrt(N) + 3;

vector<int> z_function(const string& s) {
  int n = (int) s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

vector<int> z[SQRT];
int n, a, b;
string s;

int getLargestPrefixMatch(int a, int b) {
  int last_a = a;
  int last_b = b;
  while (last_a < b && last_b < n && last_a % SQRT != 0
    && s[last_a] == s[last_b]) {
    ++last_b;
    ++last_a;
  }
  if (last_b < n && last_a < b && last_a % SQRT == 0) {
    last_a += z[last_a / SQRT][last_b - last_a];
  }
  return min(b - a, last_a - a);
}

int getLargestPrevPrefix(int ind) {
  int res = 0;
  for (int i = 0; i < ind; ++i) {
    res = max(res, getLargestPrefixMatch(i, ind));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> a >> b;
  cin >> s;

  for (int i = 0; i < s.size(); ++i) {
    if (i % SQRT == 0) {
      z[i / SQRT] = z_function(s.substr(i));
    }
  }

  array<int, N> memo { };

  for (int i = n - 1; i >= 0; --i) {
    memo[i] = a + memo[i + 1];
    int longest_old_prefix = getLargestPrevPrefix(i);
    if (longest_old_prefix != 0) {
      memo[i] = min(memo[i], b + memo[i + longest_old_prefix]);
    }
  }

  cout << memo[0] << endl;

}
