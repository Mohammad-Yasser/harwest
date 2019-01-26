#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 101;
const Long OO = 1e18;
Long score[N];

vector<int> arr;
Long memo[N][N][N];

Long solve(int l, int r, int cnt) {
  if (cnt == N) return -OO;
  if (cnt < 0) return solve(l, r, 0);

  Long& res = memo[l][r][cnt];
  if (res != -1) return res;

  res = -OO;

  for (int i = cnt; i < N; ++i) {
    res = max(res, solve(l, r, i) + score[i - cnt]);
  }

  if (l == r) {
    if (cnt == arr[l]) res = 0;
    return res;
  }

  if (cnt <= arr[l]) {
    res = max(res, solve(l + 1, r, 0));
  }

  for (int i = l + 2; i <= r; i += 2) {
    res = max(res, solve(l + 1, i - 1, 0) + solve(i, r, cnt - arr[l]));
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

  int n;
  cin >> n;
  string s;
  cin >> s;

  arr.push_back(1);
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      ++arr.back();
    } else {
      arr.push_back(1);
    }
  }

  for (int i = 1; i <= n; ++i) {
    cin >> score[i];
    for (int j = 1; j < i; ++j) {
      score[i] = max(score[i], score[j] + score[i - j]);
    }
  }

  memset(memo, -1, sizeof memo);
  cout << solve(0, arr.size() - 1, 0);

}
