#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 70000 + 5;

int r;
struct Hasher {
  int operator()(const string& s) const {
    hash<string> h;
    return h(s) ^ r;
  }
};

unordered_map<string, set<int>, Hasher> mp;

int main() {

  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  mp.reserve(70000 * 100 * 2);
  mp.max_load_factor(0.25);

  srand(time(0));
  r = rand();

  int n;
  cin >> n;

  vector<string> v(n);

  for (int ind = 0; ind < n; ++ind) {
    auto& x = v[ind];
    cin >> x;
    for (int i = 0; i < x.size(); ++i) {
      string sb = "";
      for (int j = 1; i + j <= x.size(); ++j) {
        sb += x[i + j - 1];
        if (mp[sb].size() < 2) {
          mp[sb].insert(ind);
        }
      }
    }
  }

  for (string& x : v) {
    string res = x;
    for (int i = 0; i < x.size(); ++i) {
      string sb = "";
      for (int j = 1; i + j <= x.size(); ++j) {
        sb += x[i + j - 1];
        if (sb.size() < res.size() && mp[sb].size() < 2) {
          res = sb;
        }
      }
    }
    cout << res << endl;
  }

}

