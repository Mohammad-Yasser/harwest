#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 50;
const int kMax = 500005;
int c[N];
int n, d;

char memo[N][kMax];

bool Can(int ind, int rem) {
  if (rem == 0) return true;
  if (rem < 0) return false;
  if (ind == n) return false;

  char& ret = memo[ind][rem];
  if (ret != -1) return ret;

  ret = Can(ind + 1, rem) | Can(ind + 1, rem - c[ind]);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  memset(memo, -1, sizeof memo);

  cin >> n >> d;

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  sort(c, c + n);

  vector<int> sums;
  for (int i = 0; i < kMax; ++i) {
    if (Can(0, i)) {
      sums.push_back(i);
    }
  }

  int curr_sum = 0;
  int days = 0;
  for (int i = 0; i < sums.size();) {
    int nxt = i + 1;
    while (nxt < sums.size() && sums[nxt] - curr_sum <= d) {
      ++nxt;
    }
    if (nxt == i + 1) {
      break;
    }
    i = nxt - 1;
    ++days;
    curr_sum = sums[i];
  }

  cout << curr_sum << ' ' << days;

}
