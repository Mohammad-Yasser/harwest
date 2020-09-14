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

set<int> elements;
multiset<int> gaps;

void addElement(int x) {
  auto nxt = elements.upper_bound(x);

  bool is_last = (nxt == end(elements));
  bool is_first = (nxt == begin(elements));

  auto prv = nxt;
  if (!is_first) --prv;

  if (!is_last && !is_first) {
    gaps.erase(gaps.find(*nxt - *prv));
  }
  if (!is_first) gaps.emplace(x - *prv);
  if (!is_last) gaps.emplace(*nxt - x);
  elements.emplace(x);
}

void eraseElement(int x) {
  elements.erase(x);
  auto nxt = elements.upper_bound(x);

  bool is_last = (nxt == end(elements));
  bool is_first = (nxt == begin(elements));

  auto prv = nxt;
  if (!is_first) --prv;

  if (!is_last) {
    gaps.erase(gaps.find(*nxt - x));
  }
  if (!is_first) {
    gaps.erase(gaps.find(x - *prv));
  }
  if (!is_last && !is_first) {
    gaps.emplace(*nxt - *prv);
  }
}

int solve() {
  if (elements.empty()) return 0;
  return *elements.rbegin() - *elements.begin() - *gaps.rbegin();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, q;
  cin >> n >> q;

  gaps.emplace(0);

  while (n--) {
    int p;
    cin >> p;
    addElement(p);
  }

  cout << solve() << endl;
  while (q--) {
    int t, p;
    cin >> t >> p;
    if (t == 1) {
      addElement(p);
    } else {
      eraseElement(p);
    }
    cout << solve() << endl;
  }

  return 0;
}