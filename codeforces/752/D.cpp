#include <bits/stdc++.h>
using namespace std;

unordered_map<string, pair<vector<int>, vector<int>>> words;
// map < word , vector <reversed beauties , non-reversed beauties> >

bool IsPalindrome(const string& s) {
  string rev(s.rbegin(), s.rend());
  return s == rev;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int k, n;
  cin >> k >> n;

  while (k--) {
    string s;
    int beauty;
    cin >> s >> beauty;

    string reversed(s.rbegin(), s.rend());

    if (s < reversed) {
      words[s].second.push_back(beauty);
    } else {
      words[reversed].first.push_back(beauty);
    }
  }

  int res = 0;
  vector<pair<int, int>> pos_mid;

  for (auto& pr : words) {
    sort(pr.second.first.rbegin(), pr.second.first.rend());
    sort(pr.second.second.rbegin(), pr.second.second.rend());

    if (IsPalindrome(pr.first)) {
      int i = 0;
      for (i = 0;
        i + 1 < pr.second.first.size() && pr.second.first[i] > 0
          && pr.second.first[i + 1] > 0; i += 2) {
        res += pr.second.first[i] + pr.second.first[i + 1];
      }
      if (i < pr.second.first.size() && pr.second.first[i] > 0) {
        int mid_value = pr.second.first[i];
        int non_mid_value = 0;
        if (i + 1 < pr.second.first.size()) {
          non_mid_value = max(0, mid_value + pr.second.first[i + 1]);
        }
        pos_mid.push_back( { mid_value - non_mid_value, non_mid_value });
      }
      continue;
    }
    for (int i = 0;
      i < pr.second.first.size() && i < pr.second.second.size()
        && pr.second.first[i] + pr.second.second[i] > 0; ++i) {
      res += pr.second.first[i] + pr.second.second[i];
    }
  }

  sort(pos_mid.rbegin(), pos_mid.rend());

  if (!pos_mid.empty()) {
    res += pos_mid[0].first + pos_mid[0].second;
    for (int i = 1; i < pos_mid.size(); ++i) {
      res += pos_mid[i].second;
    }
  }

  cout << res;

}
