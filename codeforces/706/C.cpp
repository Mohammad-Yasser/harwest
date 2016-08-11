#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
ll memo[N][2];
int c[N];
string arr[N][2];

int n;

#define OO LLONG_MAX

ll dp(int ind, bool prv) {
  if (ind == n) return 0;
  ll &ret = memo[ind][prv];
  if (ret != -1) return ret;
  ret = OO;
  if ((!ind || arr[ind][0] >= arr[ind - 1][prv]) && dp(ind + 1, 0) != OO)
    ret = min(ret, dp(ind + 1, 0));
  if ((!ind || arr[ind][1] >= arr[ind - 1][prv]) && dp(ind + 1, 1) != OO)
    ret = min(ret, dp(ind + 1, 1) + c[ind]);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> c[i];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i][0], arr[i][1] = arr[i][0];
    reverse(arr[i][1].begin(), arr[i][1].end());
  }
  memset(memo, -1, sizeof memo);
  cout << (dp(0,0) == OO ? -1 : dp(0,0));
}
