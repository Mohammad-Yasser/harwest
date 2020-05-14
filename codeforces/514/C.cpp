#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef double Double;

const int MOD = 179424673;

const int kBase[2] = {5, 7};

const int N = 5e6 + 5;
int base_power[N];

int arrForward[N];

void init() {
  base_power[0] = 1;
  for (int i = 1; i < N; ++i) {
    base_power[i] = 1LL * base_power[i - 1] * kBase[0] % MOD;
  }
}

vector<int> build(string s) {
  for (char& c : s) {
    ++c;
    c -= 'a';
  }

  vector<int> res(s.size() + 1, 0);
  res[0] = 1;
  for (int i = 0; i < s.size(); ++i) {
    res[i + 1] = (1LL * res[i] * kBase[0] + s[i]) % MOD;
  }
  return res;
}

set<tuple<char, int, int>> vis;

int getRangeFor(int l, int r, const vector<int>& arrForward) {
  if (l > r) return -1;
  ++l, ++r;
  int res = arrForward[r];
  int tmp_l = 1LL * arrForward[l - 1] * base_power[r - l + 1] % MOD;
  res = (res - tmp_l + MOD) % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  init();
  int n, m;
  cin >> n >> m;

  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    auto karp = build(s);
    for (int i = 0; i < s.size(); ++i) {
      int pre = getRangeFor(0, i - 1, karp);
      int suf = getRangeFor(i + 1, s.size() - 1, karp);
      vis.emplace(s[i], pre, suf);
    }
  }

  while (m--) {
    string s;
    cin >> s;
    auto karp = build(s);
    bool found = false;
    for (int i = 0; i < s.size(); ++i) {
      int pre = getRangeFor(0, i - 1, karp);
      int suf = getRangeFor(i + 1, s.size() - 1, karp);
      for (char c = 'a'; c <= 'c'; ++c) {
        if (c == s[i]) continue;
        if (vis.count(make_tuple(c, pre, suf))) {
          found = true;
          break;
        }
      }
    }
    cout << (found ? "YES" : "NO") << endl;
  }

  return 0;
}