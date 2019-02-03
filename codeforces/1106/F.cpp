#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/numeric>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))

typedef long long Long;
typedef vector<int> Row;
typedef vector<Row> Matrix;

const int MOD = 998244353;
const int N = 101;
int b[N];
int k;

struct MatrixMultiplier {
  int r = N;
  Matrix operator()(const Matrix& a, const Matrix& b) {
    int x = a.size(), y = b.size(), z = b[0].size();
    Matrix res(x, Row(z));
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < z; ++j) {
        for (int k = 0; k < y; ++k) {
          res[i][j] = (res[i][j] + 1LL * a[i][k] * b[k][j]) % (MOD - 1);
        }
      }
    }
    return res;
  }
};

Matrix identity_element(const MatrixMultiplier& m) {
  int r = m.r;
  Matrix res(r, Row(r));
  for (int i = 0; i < r; ++i) {
    res[i][i] = 1;
  }
  return res;
}

Matrix empty_matrix(int r, int c) {
  return Matrix(r, Row(c));
}

Matrix empty_matrix(int r) {
  return empty_matrix(r, r);
}

Matrix buildTransformationMatrix() {
  Matrix res = empty_matrix(k);
  for (int i = 0; i + 1 < k; ++i) {
    res[i + 1][i] = 1;
  }
  for (int i = 0; i < k; ++i) {
    res[i][k - 1] = b[i];
  }
  return res;
}

int power(int b, int p) {
  if (p == 0) return 1;
  int res = power(b, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * b % MOD;
  }
  return res;
}

int getModInverse(int x) {
  return power(x, MOD - 2);
}

int getDiscreteLog(int a, int b) {
  int sq = sqrt(MOD) + 3;
  // a^(x*sq + y) = b
  gp_hash_table<int, int> baby_map;

  int baby = 1;
  for (int i = 0; i < sq; ++i) {
    baby_map[baby] = i;
    baby = 1LL * baby * a % MOD;
  }

  int giant = 1;
  for (int i = 0; i < sq; ++i) {
    // a^y = b * a^(-x*sq)
    int y = 1LL * b * getModInverse(giant) % MOD;
    if (baby_map.find(y) != baby_map.end()) {
      return i * sq + baby_map[y];
    }
    giant = 1LL * giant * baby % MOD;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  reverse(b, b + k);

  int n, m;
  cin >> n >> m;

  Matrix mat = buildTransformationMatrix();
  mat = power(mat, n - k, MatrixMultiplier());

  int p = mat[k - 1][k - 1];
  int lg = getDiscreteLog(power(3, p), m);
  int tmp = power(3, p);

  if (lg == -1) {
    cout << -1;
    return 0;
  }
  cout << power(3, lg);
}

