#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int OO = 1e9;
int memo[N];
int t[N];
int n;

const pair<int, int> kTickets[] = { { 1, 20 }, { 90, 50 }, { 1440, 120 } };

/*
 t + x - 1 = y
 t = y + 1 - x
 */

int Solve(int ind) {
  if (ind == 0) return 0;
  int &res = memo[ind];
  if (res != -1) return res;

  res = OO;

  for (auto& ticket : kTickets) {
    int previous = lower_bound(t + 1, t + ind + 1, t[ind] - ticket.first + 1)
      - t - 1;
    res = min(res, ticket.second + Solve(previous));
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  memset(memo, -1, sizeof memo);

  cin >> n;

  int sum = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    cout << Solve(i) - sum << '\n';
    sum = Solve(i);
  }

}
