#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ' ' << x << endl;

typedef long long Long;

const int N = 1e6 + 6;

int arr[N];



int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  multiset<int> pos;
  int cnt_neg = 0;

  Long best_val = 0;
  int best_ind = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    int x = arr[i] - i;
    if (x > 0) {
      pos.insert(x);
    } else {
      ++cnt_neg;
    }
    best_val += abs(x);
  }

  Long prev = best_val;

  for (int i = n; i > 1; --i) {
    Long tmp = prev - (n - arr[i]) + (arr[i] - 1);
    --cnt_neg;

    tmp += cnt_neg;
    tmp -= pos.size();

    pos.insert((arr[i] - 1) + (n - i + 1));

    while (!pos.empty() && *pos.begin() == n - i + 1) {
      ++cnt_neg;
      pos.erase(pos.begin());
    }

    if (tmp < best_val) {
      best_val = tmp;
      best_ind = n - i + 1;
    }


    prev = tmp;
  }

  cout << best_val << ' ' << best_ind << endl;
}
