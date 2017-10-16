#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

int getSumDigits(int x) {
  int res = 0;
  while (x > 0) {
    res += x % 10;
    x /= 10;
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

  int n;
  cin >> n;

  vector<int> res;
  for (int i = 1; i <= min(n, 200); ++i) {
    int x = n - i;
    if (getSumDigits(x) == i) {
      res.push_back(x);
    }
  }

  sort(res.begin(), res.end());

  cout << res.size() << endl;

  for (int x : res) {
    cout << x << '\n';
  }

  return 0;
}
