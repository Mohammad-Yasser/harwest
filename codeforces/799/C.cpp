#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;

vector<pair<int, int>> bc, bd;

int Solve(const vector<pair<int, int>>& b, int c) {
  int res = 0;
  int curr = -1;

  multiset<int> mx;
  mx.insert(0);
  mx.insert(0);

  for (int i = int(b.size()) - 1; i > curr; --i) {
    while (curr + 1 < i && b[i].first + b[curr + 1].first <= c) {
      ++curr;

      mx.insert(b[curr].second);
      mx.erase(mx.begin());

      if (*mx.begin() != 0) {
        res = max(res, *mx.begin() + *mx.rbegin());
      }
    }
    if (curr != -1) {
      res = max(res, b[i].second + *mx.rbegin());
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, c, d;

  cin >> n >> c >> d;

  for (int i = 0; i < n; ++i) {
    int b, p;
    cin >> b >> p;
    char c;
    cin >> c;

    if (c == 'C') {
      bc.emplace_back(p, b);
    } else {
      bd.emplace_back(p, b);
    }
  }

  sort(bc.begin(), bc.end());
  sort(bd.begin(), bd.end());

  int res = max(Solve(bc, c), Solve(bd, d));

  int mx_c = 0;
  int mx_d = 0;

  for (auto& p : bc) {
    if (p.first <= c) {
      mx_c = max(mx_c, p.second);
    }
  }

  for (auto& p : bd) {
    if (p.first <= d) {
      mx_d = max(mx_d, p.second);
    }
  }

  if (mx_c > 0 && mx_d > 0) {
    res = max(res, mx_c + mx_d);
  }

  cout << res;
}
