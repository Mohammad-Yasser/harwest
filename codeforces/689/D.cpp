#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const int log_N = log2(2e5) + 1;

int mxa[N][log_N], mnb[N][log_N];
int a[N], b[N];

int lg[N];

int n;

inline void BuildSparseTable(int table[][log_N], int arr[],
                             int (*fn)(const int &, const int &)) {
  for (int i = n - 1; i >= 0; --i) {
    table[i][0] = arr[i];
    for (int j = 1; i + (1 << j) <= n; ++j)
      table[i][j] = fn(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
  }
}

inline int max_(const int &a, const int &b) { return max(a, b); }
inline int min_(const int &a, const int &b) { return min(a, b); }

int GetVal(int table[][log_N], int start, int end,
           int (*fn)(const int &, const int &)) {
  int l = lg[end - start + 1];
  return fn(table[start][l], table[end - (1 << l) + 1][l]);
}

int solve(int start) {
  int low = start, high = n - 1, mid, ans = n;
  while (low <= high) {
    mid = (low + high) / 2;
    if (GetVal(mxa, start, mid, max_) > GetVal(mnb, start, mid, min_))
      ans = mid, high = mid - 1;
    else
      low = mid + 1;
  }

  int h = ans;

  low = start, high = n - 1, ans = low - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (GetVal(mxa, start, mid, max_) < GetVal(mnb, start, mid, min_))
      ans = mid, low = mid + 1;
    else
      high = mid - 1;
  }
  return h - ans - 1;
}

int main() {
  for (int i = 2; i <= N; ++i) lg[i] = (i == (i & -i)) + lg[i - 1];

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  BuildSparseTable(mxa, a, &max_);
  BuildSparseTable(mnb, b, &min_);

  //  for (int i = 0; i < n; ++i)
  //    cout << GetVal(mxa, 0, i, max_) << ' ' << mxa[0][i] << endl;
  //  return 0;

  long long ans = 0;
  for (int i = 0; i < n; ++i) ans += solve(i);

  cout << ans << endl;
  return 0;
}
