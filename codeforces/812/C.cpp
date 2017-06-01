#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;

int s;
int n;

int arr[N];
Long tmp[N];

Long GetMinCost(int k) {
  for (int i = 0; i < n; ++i) {
    tmp[i] = arr[i] + 1LL * (i + 1) * k;
  }
  sort(tmp, tmp + n);
  Long cost = 0;
  for (int i = 0; i < k; ++i) {
    cost += tmp[i];
  }
  return cost;
}

pair<int, int> Bs() {
  int low = 0, high = min(n, 3000), mid, ans_k = 0, ans_cost = 0;

  while (low <= high) {
    mid = (low + high) / 2;
    Long cost = GetMinCost(mid);
    if (cost <= s) {
      ans_k = mid;
      ans_cost = cost;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return {ans_k , ans_cost};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n >> s;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  auto res = Bs();

  cout << res.first << ' ' << res.second << '\n';

}
