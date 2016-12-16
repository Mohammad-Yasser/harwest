#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

 Let the number of games = x.

 Since each player i wants to play as non-supervisor a[i] times,
 the sum of the times other player are supervisors must be >= a[i].

 Also, for each player i, he can be a supervisor at most x - a[i] times.

 Hence, for each player i, the following condition must be met:
 Sum of (x - a[j]) for each other player j, must be >= a[i].
 (n - 1) * x - total_sum + a[i] >= a[i]
 (n - 1) * x - total_sum  >= 0
 (n - 1) * x  >= total_sum
 x >= total_sum / (n - 1)
 */

const int N = 100005;
int arr[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  ll sum = 0;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    sum += arr[i];
    mx = max(mx, arr[i]);
  }

  cout << max((ll) mx, (sum + n - 2) / (n - 1));

}
