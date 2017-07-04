#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ' ' << x << endl;

typedef long long Long;

const int N = 1e6 + 6;

int arr[N];

int cnt_pos[2 * N];

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  int total_neg = 0;

  Long best_val = 0;
  int best_ind = 0;
  int total_pos = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    int x = arr[i] - i;
    if (x > 0) {
      ++cnt_pos[x];
      ++total_pos;
    } else {
      ++total_neg;
    }
    best_val += abs(x);
  }

  Long prev = best_val;

  for (int i = n; i > 1; --i) {
    Long tmp = prev - (n - arr[i]) + (arr[i] - 1);
    --total_neg;

    tmp += total_neg;
    tmp -= total_pos;

    ++cnt_pos[(arr[i] - 1) + (n - i + 1)];
    ++total_pos;

    total_neg += cnt_pos[n - i + 1];
    total_pos -= cnt_pos[n - i + 1];

    if (tmp < best_val) {
      best_val = tmp;
      best_ind = n - i + 1;
    }

    prev = tmp;
  }

  cout << best_val << ' ' << best_ind << endl;
}
