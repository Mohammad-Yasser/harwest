#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 3e5 + 5;
vector<int> c[N];

int n;
int getLast(const vector<int>& v) {
  int res = n;
  for (int i = v.size() - 1; i >= 0; --i) {
    if (v[i] == res) {
      --res;
    } else {
      return res;
    }
  }
  return res;
}

int getFirst(const vector<int>& v) {
  int res = 1;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == res) {
      ++res;
    } else {
      return res;
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

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    c[x].push_back(i);
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (c[i].empty()) continue;
    int last = getLast(c[i]);
    res = max(res, last - c[i][0]);
    int first = getFirst(c[i]);
    res = max(res, c[i].back() - first);
  }

  cout << res;

}
