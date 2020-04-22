#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

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
int n, k;

int first_0 = n, last_0 = 0, first_1 = n, last_1 = 0;
bool winning(const string& s) {
  first_0 = n, last_0 = 0, first_1 = n, last_1 = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      first_0 = min(first_0, i);
      last_0 = i;
    } else {
      first_1 = min(first_1, i);
      last_1 = i;
    }
  }

  return (min(last_0 - first_0, last_1 - first_1) + 1 <= k);
}

string flip(const string& s, int l, char c) {
  int r = l + k - 1;
  if (l < 0 || r >= n) return "";

  string res = s;
  for (int i = l; i <= r; ++i) {
    res[i] = c;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> k;
  string s;
  cin >> s;

  if (winning(s)) {
    cout << "tokitsukaze" << endl;
    return 0;
  }

  vector<string> candidates;
  candidates.emplace_back(flip(s, 0, '0'));
  candidates.emplace_back(flip(s, first_1 + 1, '0'));
  candidates.emplace_back(flip(s, last_1 + 1, '0'));

  candidates.emplace_back(flip(s, 0, '1'));
  candidates.emplace_back(flip(s, first_0 + 1, '1'));
  candidates.emplace_back(flip(s, last_0 + 1, '1'));

  for (auto& s : candidates) {
    if (!s.empty() && !winning(s)) {
      cout << "once again" << endl;
      return 0;
    }
  }

  cout << "quailty" << endl;

  return 0;
}
