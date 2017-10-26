#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int B = 10;
const int M = 1 << B;

const int N = 5e5 + 5;

pair<char, int> arr[N];

int calc(int n, int op_ind, int mask) {
  char c = arr[op_ind].first;
  int x = (arr[op_ind].second & mask);

  if (c == '|') {
    n |= x;
  }
  if (c == '^') {
    n ^= x;
  }
  if (c == '&') {
    n &= x;
  }
  return n;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int o = 0, a = M - 1, x = 0;

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }

  for (int mask = 1; mask < M; mask *= 2) {
    int res_1 = mask;
    int res_0 = 0;

    for (int i = 0; i < n; ++i) {
      res_1 = calc(res_1, i, mask);
      res_0 = calc(res_0, i, mask);
    }

    if (res_0 == 0 && res_1 == mask) {
      continue;
    }

    if (res_0 == 0 && res_1 == 0) {
      a ^= mask;
      continue;
    }

    if (res_0 == mask && res_1 == mask) {
      o |= mask;
      continue;
    }

    if (res_0 == mask && res_1 == 0) {
      x |= mask;
      continue;
    }
  }

  cout << 3 << endl;
  cout << "& " << a << endl;
  cout << "| " << o << endl;
  cout << "^ " << x << endl;

}

