#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const int N = 200005;
const int A = 27;
int pre[N];
int suf[N];

vector<int> occ[A];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  string s, t;
  cin >> s >> t;

  for (int i = 0; i < t.size(); ++i) {
    occ[t[i] - 'a'].push_back(i);
  }

  int curr = 0;

  for (int i = 0; i < s.size(); ++i) {
    pre[i] = curr;
    if (s[i] == t[curr]) {
      ++curr;
    }
  }

  curr = 0;
  reverse(t.begin(), t.end());
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == t[curr]) {
      ++curr;
    }
    suf[i] = curr;
  }
  reverse(t.begin(), t.end());

  bool yes = true;

  for (auto& v : occ) {
    v.push_back(N);
  }

  for (int i = 0; i < s.size(); ++i) {
    auto& occ = ::occ[s[i] - 'a'];
    int pos = *lower_bound(occ.begin(), occ.end(), t.size() - suf[i]);

    yes &= pre[i] >= pos;
  }

  cout << (yes ? "Yes" : "No");

}
