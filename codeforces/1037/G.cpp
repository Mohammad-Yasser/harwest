#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;
const int A = 26;
string s;

int first_occ[A][N][2];
int occ_id[N];
vector<int> pos[A];
vector<int> acc_grundy[A];
int memo[N][A][2];

int solve(int l, int r) {
  if (r < l) return 0;
  bool maximal_right = (r + 1 != s.size()
    && first_occ[s[r + 1] - 'a'][l][0] == r + 1);
  bool maximal_left = (l != 0 && first_occ[s[l - 1] - 'a'][r][1] == l - 1);

  if (maximal_right && memo[l][s[r + 1] - 'a'][0] != -1) {
    return memo[l][s[r + 1] - 'a'][0];
  } else if (maximal_left && memo[r][s[l - 1] - 'a'][1] != -1) {
    return memo[r][s[l - 1] - 'a'][1];
  }

  int mex = 0;
  for (int ch = 0; ch < A; ++ch) {
    if (pos[ch].empty()) continue;
    int first_occ_from_left = first_occ[ch][l][0];
    int first_occ_from_right = first_occ[ch][r][1];
    if (first_occ_from_left > r) continue;
    int res = 0;
    if (acc_grundy[ch].size() != pos[ch].size()) {
      for (int i = occ_id[first_occ_from_left];
        i < occ_id[first_occ_from_right]; ++i) {
        res ^= solve(pos[ch][i] + 1, pos[ch][i + 1] - 1);
      }
    } else {
      res = acc_grundy[ch][occ_id[first_occ_from_left]]
        ^ acc_grundy[ch][occ_id[first_occ_from_right]];
    }
    res ^= solve(l, first_occ_from_left - 1);
    res ^= solve(first_occ_from_right + 1, r);
    mex |= (1 << res);
  }

  int res = 0;
  while ((mex >> res) & 1) {
    ++res;
  }
  if (maximal_right) {
    memo[l][s[r + 1] - 'a'][0] = res;
  }
  if (maximal_left) {
    memo[r][s[l - 1] - 'a'][1] = res;
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

  cin >> s;

  memset(memo, -1, sizeof memo);

  for (int i = 0; i < s.size(); ++i) {
    int ch = s[i] - 'a';
    occ_id[i] = pos[ch].size();
    pos[ch].push_back(i);
  }
  for (int ch = 0; ch < A; ++ch) {
    int lst = N;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] - 'a' == ch) {
        lst = i;
      }
      first_occ[ch][i][0] = lst;
    }
  }
  for (int ch = 0; ch < A; ++ch) {
    int lst = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] - 'a' == ch) {
        lst = i;
      }
      first_occ[ch][i][1] = lst;
    }
  }

  for (int ch = 0; ch < A; ++ch) {
    if (pos[ch].empty()) continue;
    acc_grundy[ch].push_back(0);

    for (int i = 0; i + 1 < pos[ch].size(); ++i) {
      int res = solve(pos[ch][i] + 1, pos[ch][i + 1] - 1);
      acc_grundy[ch].push_back(acc_grundy[ch].back() ^ res);
    }
  }


  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << (solve(l, r) != 0 ? "Alice" : "Bob") << endl;
  }

}