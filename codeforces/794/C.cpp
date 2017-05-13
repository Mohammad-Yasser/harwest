#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

string Solve(string x, string y) {
  string a[2] = { x, y };

  sort(a[0].rbegin(), a[0].rend());
  sort(a[1].begin(), a[1].end());

  deque<char> dq[2];

  dq[0].insert(dq[0].begin(), a[0].begin(), a[0].end());
  dq[1].insert(dq[1].begin(), a[1].begin(), a[1].end());
  int n = a[0].size();

  while (dq[0].size() > (n + 1) / 2) {
    dq[0].pop_front();
  }

  while (dq[1].size() > n / 2) {
    dq[1].pop_front();
  }

  bool curr = 0;

  string res(n, '?');

  int first = 0, last = n - 1;

  for (int i = 0; i < n; ++i) {
    curr = i & 1;

    if (dq[0].back() < dq[1].back()) {
      res[first] = dq[curr].back();
      ++first;
      dq[curr].pop_back();
      continue;
    }

    res[last] = dq[curr].front();
    dq[curr].pop_front();
    --last;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  string a, b;
  cin >> a >> b;

  cout << Solve(a, b);

}
