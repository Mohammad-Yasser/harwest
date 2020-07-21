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

const int N = 1e5 + 5;
int n, x, y;
vector<int> b;

int freq[N];
int match_indices[N];
set<pair<int, int>> cnt;
vector<int> match_colors[N];
void init() {
  cnt.clear();
  for (int i = 0; i < n + 3; ++i) {
    freq[i] = 0;
    match_indices[i] = 0;
    match_colors[i].clear();
  }
}

void buildFreq() {
  for (int x : b) {
    ++freq[x];
  }
  for (int i = 1; i <= n + 1; ++i) {
    if (freq[i] != 0) {
      cnt.emplace(freq[i], i);
    }
  }
}

int getMissingElement() {
  for (int i = 1; i <= n + 1; ++i) {
    if (freq[i] == 0) return i;
  }
  assert(false);
  return -1;
}

void buildMatchIndices() {
  for (int i = 0; i < x; ++i) {
    auto it = cnt.end();
    --it;
    auto curr = *it;
    cnt.erase(it);
    --curr.first;
    ++match_indices[curr.second];
    if (curr.first != 0) {
      cnt.emplace(curr);
    }
  }
}

bool buildMatchColors() {
  if (y == 0) return true;
  if (cnt.empty()) return false;
  int y = ::y;
  vector<int> v1;
  for (auto p : cnt) {
    while (p.first--) {
      v1.emplace_back(p.second);
    }
  }
  auto v2 = v1;
  rotate(begin(v2), begin(v2) + sz(v1) - cnt.rbegin()->first, end(v2));

  for (int i = 0; i < sz(v1); ++i) {
    if (v1[i] == v2[i]) continue;
    if (y == 0) break;
    --y;
    match_colors[v1[i]].emplace_back(v2[i]);
  }
  return y == 0;
}

void check(const vector<int>& a) {
  int x = ::x;
  int y = ::y;
  y += x;
  for (int i = 0; i < n; ++i) {
    x -= (a[i] == b[i]);
  }
  assert(x == 0);
  multiset<int> ms(all(a));
  for (int i = 0; i < n; ++i) {
    auto it = ms.find(b[i]);
    if (it == end(ms)) continue;
    ms.erase(it);
    --y;
  }
  assert(y == 0);
}

void solve() {
  if (y < x) {
    cout << "NO" << endl;
    return;
  }
  y -= x;
  init();
  buildFreq();

  buildMatchIndices();
  if (!buildMatchColors()) {
    cout << "NO" << endl;
    return;
  }

  int missing_element = getMissingElement();
  vector<int> res(n, missing_element);
  for (int i = 0; i < n; ++i) {
    if (match_indices[b[i]] > 0) {
      --match_indices[b[i]];
      res[i] = b[i];
      continue;
    }
    if (!match_colors[b[i]].empty()) {
      res[i] = match_colors[b[i]].back();
      match_colors[b[i]].pop_back();
    }
  }

  check(res);
  cout << "YES" << endl;
  cout << res << endl;
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
    cin >> n >> x >> y;
    b.resize(n);
    cin >> b;
    solve();
  }
  return 0;
}