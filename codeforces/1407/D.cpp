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
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 3e5 + 5;
int first_smaller[N];
int first_larger[N];
int dp[N];

vector<int> arr;
int n;

void build() {
  first_larger[n - 1] = first_smaller[n - 1] = n;
  dp[n] = INT_MAX / 2;

  for (int i = n - 2; i >= 0; --i) {
    dp[i] = dp[i + 1];
    int& fl = first_larger[i];
    fl = i + 1;
    while (fl != n && arr[fl] < arr[i]) {
      if (arr[fl] != arr[first_larger[fl]]) {
        dp[i] = min(dp[i], dp[first_larger[fl]]);
      }
      fl = first_larger[fl];
    }
    int& fs = first_smaller[i];
    fs = i + 1;
    while (fs != n && arr[fs] > arr[i]) {
      if (arr[fs] != arr[first_smaller[fs]]) {
        dp[i] = min(dp[i], dp[first_smaller[fs]]);
      }
      fs = first_smaller[fs];
    }
    ++dp[i];
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  arr.resize(n);
  cin >> arr;
  build();
  cout << dp[0] << endl;
  return 0;
}