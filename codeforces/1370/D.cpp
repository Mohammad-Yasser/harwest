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
const int N = 2e5 + 5;
int arr[N];
int n;
int k;
bool valid(int mx) {
  int cnt = 0;
  for (int i = 0; i + (k % 2 == 0) < n; ++i) {
    if (arr[i] <= mx) {
      ++cnt;
      ++i;
    }
  }
  if (cnt >= (k + 1) / 2) return true;
  cnt = 0;
  for (int i = 1; i + (k % 2 == 1) < n; ++i) {
    if (arr[i] <= mx) {
      ++cnt;
      ++i;
    }
  }
  return cnt >= k / 2;
}

int bs() {
  int low = 1, high = 1e9 + 5, ans;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (valid(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
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

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  cout << bs() << endl;

  return 0;
}