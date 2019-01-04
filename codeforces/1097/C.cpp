#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 5e5 + 5;

int cnt[N][2];

pair<int, int> getV(const string& s) {
  pair<int, int> res = { 0, 0 };

  int open = 0;

  for (char c : s) {
    if (c == '(') {
      ++open;
    } else {
      --open;
      res.first = max(res.first, -open);
    }
  }

  open = 0;
  string tmp = s;
  reverse(tmp.begin(), tmp.end());

  for (char c : tmp) {
    if (c == '(') {
      --open;
      res.second = max(res.second, -open);
    } else {
      ++open;
    }
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

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    auto tmp = getV(s);
    if (tmp.first != 0 && tmp.second != 0) continue;
    if (tmp.first != 0) {
      ++cnt[tmp.first][0];
    } else {
      ++cnt[tmp.second][1];
    }
  }

  int res = cnt[0][1] / 2;
  for (int i = 1; i < N; ++i) {
    res += min(cnt[i][0], cnt[i][1]);
  }

  cout << res;
}
