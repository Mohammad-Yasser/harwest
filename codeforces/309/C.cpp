#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
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
int n, m;

int cnt[31];

bool valid(const vector<int>& a, const vector<int>& b, int mid) {
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < mid; ++i) {
    ++cnt[b[i]];
  }
  for (int x : a) {
    for (int i = 30; i >= 0; --i) {
        if (cnt[i] == 0) continue;
        int tmp = min(cnt[i], x >> i);
        cnt[i] -= tmp;
        x -= tmp << i;
    }
  }
  return *max_element(all(cnt)) == 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  cin >> n >> m;
  vector<int> a(n);
  cin >> a;
  sort(rall(a));
  vector<int> b(m);
  cin >> b;
  sort(all(b));

  int low = 1, high = m, ans = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (valid(a, b, mid)) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
  }

  cout << ans << endl;

  return 0;
}