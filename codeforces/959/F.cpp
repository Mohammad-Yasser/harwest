#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = (1 << 20);
const int MOD = round(1e9 + 7);
int arr[N];
int first_possible[N];
int redundant[N];

int pw2[N];

void build() {
  pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw2[i] = 2LL * pw2[i - 1] % MOD;
  }
}

bool isSet(int n, int b) {
  return (n >> b) & 1;
}

int getRank(const vector<int>& mat) {
  vector<int> res = mat;
  int rank = 0;
  for (int row = 0, col = 0; row < res.size() && col < 20; ++col) {
    for (int i = row; i < res.size(); ++i) {
      if (isSet(res[i], col)) {
        swap(res[row], res[i]);
        break;
      }
    }
    if (!isSet(res[row], col)) continue;
    ++rank;
    for (int i = 0; i < res.size(); ++i) {
      if (i == row) continue;
      if (isSet(res[i], col)) {
        res[i] ^= res[row];
      }
    }
    ++row;
  }

  return rank;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  build();

  int n, q;
  cin >> n >> q;

  fill(first_possible, first_possible + N, N);
  first_possible[0] = 0;

  vector<int> mat;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    redundant[i] = redundant[i - 1];
    mat.push_back(arr[i]);
    if (getRank(mat) != mat.size()) {
      ++redundant[i];
      mat.pop_back();
      continue;
    }
    for (int j = 0; j < N; ++j) {
      if (first_possible[j] != N) continue;
      if (first_possible[j ^ arr[i]] != N) {
        first_possible[j] = i;
      }
    }
  }

  while (q--) {
    int l, x;
    cin >> l >> x;
    if (first_possible[x] > l) {
      cout << 0 << endl;
      continue;
    }
    cout << pw2[redundant[l]] << endl;
  }

}
