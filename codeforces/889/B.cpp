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

const int A = 'z' - 'a' + 1;
int prv[A];
int nxt[A];

bool checkUniqueCharacters(const string& s) {
  static vector<bool> vis;
  vis.resize(A);
  fill(all(vis), false);
  for (char c : s) {
    if (vis[c]) return false;
    vis[c] = true;
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

  int n;
  cin >> n;
  memset(prv, -1, sizeof prv);
  memset(nxt, -1, sizeof nxt);

  vector<bool> vis(A, false);
  string s;
  while (n--) {
    cin >> s;
    for (char& c : s) {
      c -= 'a';
      vis[c] = true;
    }
    if (!checkUniqueCharacters(s)) {
      cout << "NO" << endl;
      return 0;
    }
    for (int i = 0; i + 1 < sz(s); ++i) {
      if (nxt[s[i]] != -1 && nxt[s[i]] != s[i + 1]) {
        cout << "NO" << endl;
        return 0;
      }
      if (prv[s[i + 1]] != -1 && prv[s[i + 1]] != s[i]) {
        cout << "NO" << endl;
        return 0;
      }

      nxt[s[i]] = s[i + 1];
      prv[s[i + 1]] = s[i];
    }
  }

  string res;
  res.reserve(2e5);
  while (*max_element(all(vis))) {
    int curr = 0;
    for (int i = 0; i < A; ++i) {
      if (vis[i] && prv[i] == -1) {
        curr = i;
        break;
      }
    }
    do {
      if (!vis[curr]) {
        cout << "NO" << endl;
        return 0;
      }
      res += char('a' + curr);
      vis[curr] = false;
      curr = nxt[curr];
    } while (curr != -1);
  }

  cout << res << endl;
  return 0;
}