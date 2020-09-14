#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 2e5 + 5;

int dp[N][2];
bool hard[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> hard[i];
    }
    dp[n][0] = dp[n][1] = 0;
    dp[n - 1][0] = 0;
    dp[n - 1][1] = hard[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      dp[i][0] = min(dp[i + 1][1], dp[i + 2][1]);
      dp[i][1] =
          min(dp[i + 1][0] + hard[i], dp[i + 2][0] + hard[i] + hard[i + 1]);
    }
    cout << dp[0][1] << endl;
  }
  return 0;
}