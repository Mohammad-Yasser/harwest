#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

string good;
string pattern;

bool matches(const string& s, const string& p) {
  if (s.size() != p.size()) return false;

  for (int i = 0; i < s.size(); ++i) {
    if (p[i] == '?' && good.find(s[i]) != string::npos) continue;
    if (s[i] != p[i]) return false;
  }
  return true;
}

bool is_bad(const string& s) {
  for (char c : s) {
    if (good.find(c) != string::npos) return false;
  }
  return true;
}

bool matches(const string& s) {
  if (s.size() < pattern.size() - 1) return false;
  int ast = pattern.find('*');
  if (ast == string::npos) return matches(s, pattern);
  string first = s.substr(0, ast);
  string last = s.substr(s.size() - (pattern.size() - ast - 1));
  string middle = s.substr(first.size(), s.size() - first.size() - last.size());

  return matches(first, pattern.substr(0, first.size()))
    && matches(last, pattern.substr(pattern.size() - last.size()))
    && is_bad(middle);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> good >> pattern;

  int q;
  cin >> q;

  while (q--) {
    string s;
    cin >> s;

    cout << (matches(s) ? "YES" : "NO") << '\n';
  }

}
