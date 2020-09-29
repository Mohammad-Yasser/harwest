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

const int N = 1e4 + 4;
int cnt[N];
int arr[N];

struct Op {
  int i, j, x;
  Op(int i, int j, int x) : i(i), j(j), x(x) {}
};
int n;

bool solve(vector<Op>& ops) {
  int sum = accumulate(arr + 1, arr + n + 1, 0);
  if (sum % n != 0) return false;
  int avg = sum / n;
  for (int i = 2; i <= n; ++i) {
    if (arr[i] % i != 0) {
      int x = i - arr[i] % i;
      ops.emplace_back(1, i, x);
      arr[i] += x;
    }
    ops.emplace_back(i, 1, arr[i] / i);
  }
  for (int i = 2; i <= n; ++i) {
    ops.emplace_back(1, i, avg);
  }
  return true;
}

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
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }
    vector<Op> ops;
    if (solve(ops)) {
      cout << sz(ops) << endl;
      for (auto& op : ops) {
        cout << op.i << " " << op.j << " " << op.x << endl;
      }
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}