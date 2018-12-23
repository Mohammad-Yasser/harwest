#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

int k;
string s, a, b;

void buildRem(vector<int>& to, vector<int>& from, int ind, bool inc) {
  int f_j = (inc ? 0 : k - 1);
  for (int i = ind; i < s.size(); ++i) {
    int x = s[i] - 'a';
    if (to[x] != -1) continue;

    while (from[f_j] != -1) {
      if (inc) {
        ++f_j;
      } else {
        --f_j;
      }
    }
    from[f_j] = x;
    to[x] = f_j;
  }

  for (int x = 0; x < k; ++x) {
    if (to[x] != -1) continue;
    while (from[f_j] != -1) {
      if (inc) {
        ++f_j;
      } else {
        --f_j;
      }
    }
    from[f_j] = x;
    to[x] = f_j;
  }
}

bool check(const vector<int>& to) {
  string tmp = s;
  for (char& c : tmp) {
    c = 'a' + to[c - 'a'];
  }
  return a <= tmp && tmp <= b;
}

string genRes(const vector<int>& to) {
  string res(k, 0);
  for (int i = 0; i < k; ++i) {
    res[i] = 'a' + to[i];
  }
  return res;
}

void print(const vector<int>& v) {
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
}

string solve() {
  vector<int> to(k, -1), from(k, -1);
  for (int i = 0; i < s.size(); ++i) {
    int x = s[i] - 'a';
    int y = a[i] - 'a';
    int z = b[i] - 'a';

    if (to[x] != -1) {
      if (y > to[x] || to[x] > z) return "";
      if (y == z) continue;
      if (to[x] > y && to[x] < z) {
        buildRem(to, from, i + 1, true);
        assert(check(to));
        return genRes(to);
      }
      buildRem(to, from, i + 1, to[x] > y);
      if (check(to)) {
        return genRes(to);
      }
      return "";
    }

    if (y == z) {
      to[x] = y;
      if (from[y] != -1) return "";
      from[y] = x;
      continue;
    }

    for (int j = y + 1; j < z; ++j) {
      if (from[j] == -1) {
        to[x] = j;
        from[j] = x;
        buildRem(to, from, i + 1, true);
        assert(check(to));
        return genRes(to);
      }
    }
    vector<int> tmp_to = to, tmp_from = from;
    if (from[y] == -1) {
      tmp_to[x] = y;
      tmp_from[y] = x;
      buildRem(tmp_to, tmp_from, i + 1, false);
      if (check(tmp_to)) {
        return genRes(tmp_to);
      }
    }
    if (from[z] == -1) {
      to[x] = z;
      from[z] = x;
      buildRem(to, from, i + 1, true);
      if (check(to)) {
        return genRes(to);
      }
    }
    return "";
  }
  buildRem(to, from, s.size(), true);
  assert(check(to));
  return genRes(to);
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
    cin >> k >> s >> a >> b;
    string res = solve();
    if (res.empty()) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    cout << res << endl;
  }

}
