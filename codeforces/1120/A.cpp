#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;

const int N = 5e5 + 5;

int m, k, n, s;

int a[N];
int b[N];

int to[N];

void build() {
  array<int, N> running_cnt { };

  int i = 0;
  int j = 0;

  memset(to, -1, sizeof to);

  int invalid = N - count(b, b + N, 0);

  while (j < m) {
    if (++running_cnt[a[j]] == b[a[j]]) {
      --invalid;
    }
    while (invalid == 0) {
      to[i] = j;
      if (running_cnt[a[i]] == b[a[i]]) {
        ++invalid;
      }
      --running_cnt[a[i]];
      ++i;
    }
    ++j;
  }
}

bool answer(int ind) {
  int res = max(0, to[ind] - ind + 1 - k) + ind % k;
  if ((m - res) < n * k) return false;
  cout << res << endl;

  for (int i = ind / k * k; i < ind; ++i) {
    cout << i + 1 << " ";
  }

  array<int, N> running_cnt { };
  res -= ind % k;
  for (int i = ind; i < to[ind] && res > 0; ++i) {
    if (++running_cnt[a[i]] > b[a[i]]) {
      --running_cnt[a[i]];
      --res;
      cout << i + 1 << " ";
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> m >> k >> n >> s;

  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < s; ++i) {
    int x;
    cin >> x;
    ++b[x];
  }

  build();

  for (int i = 0; i < m; ++i) {
    if (to[i] == -1) continue;
    if (answer(i)) {
      return 0;
    }
  }

  cout << -1;

}
