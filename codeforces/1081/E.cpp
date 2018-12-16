//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse4.1,sse4.2,ssse3,sse3,sse2,sse,avx")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 100005;
const int MX = 200005;

vector<Long> squares;
vector<pair<int, int>> diff[MX];

void build() {
  for (int i = 0; i < N; ++i) {
    squares.push_back(1LL * i * i);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N && squares[j] - squares[i] < MX; ++j) {
      diff[squares[j] - squares[i]].emplace_back(i, j);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  build();

  int n;
  cin >> n;

  vector<Long> v(n + 1);
  for (int i = 2; i <= n; i += 2) {
    cin >> v[i];
  }

  Long curr = 0;
  for (int i = 1; i < n; i += 2) {
    int ind = lower_bound(diff[v[i + 1]].begin(), diff[v[i + 1]].end(),
      make_pair( (int)curr + 1, 0 )) - diff[v[i + 1]].begin();
    if (ind == diff[v[i + 1]].size()) {
      cout << "No";
      return 0;
    }
    Long nxt = diff[v[i + 1]][ind].first;
    v[i] = nxt * nxt - curr * curr;
    curr = diff[v[i + 1]][ind].second;
  }

  v.erase(v.begin());
  cout << "Yes" << endl;
  for (Long x : v) {
    cout << x << " ";
  }

}
