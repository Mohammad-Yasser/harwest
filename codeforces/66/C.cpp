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

char DEL = '\\';

vector<string> split(const string& s) {
  vector<string> res;
  string curr;
  for (char c : s) {
    if (c == DEL) {
      res.emplace_back(curr);
    }
    curr += c;
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

  unordered_map<string, int> cnt_files;
  unordered_map<string, unordered_set<string>> subfolders;

  string s;
  while (cin >> s) {
    int root_folder_length = find(begin(s) + 3, end(s), DEL) - begin(s);
    string root_folder = s.substr(0, root_folder_length);
    s = s.substr(root_folder_length + 1);
    auto subs = split(s);
    for (auto& sub : subs) {
      subfolders[root_folder].emplace(sub);
    }
    ++cnt_files[root_folder];
  }
  int mx_files = 0;
  for (auto& p : cnt_files) {
    mx_files = max(mx_files, p.second);
  }

  int mx_sub = 0;
  for (auto& p : subfolders) {
    mx_sub = max(mx_sub, sz(p.second));
  }
  cout << mx_sub << " " << mx_files << endl;

  return 0;
}