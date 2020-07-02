#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
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

const int N = 5e5 + 5;
int arr[N];
int n, r;
Long k;
Long defence[N];

void build_defence() {
  arr[0] = arr[n + 1] = 0;
  for (int i = 1; i <= 1 + r; ++i) {
    defence[1] += arr[i];
  }
  for (int i = 2; i <= n; ++i) {
    defence[i] =
        defence[i - 1] + arr[min(n + 1, i + r)] - arr[max(0, i - r - 1)];
  }
}

Long add[N];

bool valid(Long ans) {
  memset(add, 0, sizeof add);
  Long k = ::k;
  Long extra = 0;
  for (int i = 1; i <= n && k >= 0; ++i) {
    int ex = max(0, i - r - 1);
    extra -= add[ex];
    if (defence[i] + extra >= ans) continue;
    Long needed = ans - defence[i] - extra;
    k -= needed;
    int nxt = min(n + 1, i + r);
    add[nxt] += needed;
    extra += needed;
  }

  return k >= 0;
}

Long solve() {
  Long l = 0, r = LLONG_MAX - 1, ans = 0;
  while (l <= r) {
    Long mid = l / 2 + r / 2 + (l & r & 1);
    if (valid(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> r >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  build_defence();
  cout << solve() << endl;

  return 0;
}