#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 53;

int memo[N];
int n;

int arr[N];
int acc[N];

int solve(int ind) {
  if (ind == n) return 0;
  int& res = memo[ind];
  if (res != -1) return res;

  res = solve(ind + 1);
  res = max(res, arr[ind] + acc[ind + 1] - solve(ind + 1));

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  memset(memo, -1, sizeof memo);
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    acc[i] = acc[i + 1] + arr[i];
  }
  cout << acc[0] - solve(0) << ' ' << solve(0);
}

