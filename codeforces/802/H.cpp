#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

string p = "abcdef";
string s = "aabcdef";

/*
 *  1 5  15
 * 1 4 10 20 35
 *  3 6 10
 */

int Count(int i, int j) {
  if (i == p.size()) return 1;
  if (j == s.size()) return 0;

  int res = Count(i, j + 1);
  if (p[i] == s[j]) {
    res += Count(i + 1, j + 1);
  }
  return res;
}

const int N = 200;
int x[N];
int a[N];

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  int ind;
  int sum = 0;

  for (ind = 1; sum <= n; ++ind) {
    x[ind] = x[ind - 1] + ind * (ind + 1) * (ind + 2) * (ind + 3) / 24;
    sum += x[ind];
  }

  --ind;
  sum -= x[ind--];

  n -= sum;

  for (int i = ind; n > 0; --i) {
    while (n >= x[i]) {
      n -= x[i];
      ++a[i];
    }
  }

  string s;
  for (int i = 1; i <= ind; ++i) {
    s += string(1 + a[ind - i + 1], 'a');
    s += "bcdef";
  }

  cout << s << ' ' << p << endl;

  return 0;
}
