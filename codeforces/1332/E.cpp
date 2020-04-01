#include <bits/stdc++.h>

#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;
typedef long long Long;

typedef vector<int> Row;
typedef vector<Row> Matrix;

const int MOD = 998244353;
const int MatrixLength = 2;

struct MatrixMultiplier {
  int r = MatrixLength;
  Matrix operator()(const Matrix& a, const Matrix& b) {
    int x = a.size(), y = b.size(), z = b[0].size();
    Matrix res(x, Row(z));
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < z; ++j) {
        for (int k = 0; k < y; ++k) {
          res[i][j] = (res[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
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

Matrix empty_matrix(int r, int c) { return Matrix(r, Row(c)); }

Matrix empty_matrix(int r) { return empty_matrix(r, r); }

int main() {
  ios_base::sync_with_stdio(false);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, m, l, r;
  cin >> n >> m >> l >> r;
  int cnt_even = r / 2 - (l - 1) / 2;
  int cnt_odd = (r + 1) / 2 - l / 2;

  MatrixMultiplier matrix_multiplier;
  Matrix transformation_matrix = {{cnt_even, cnt_odd}, {cnt_odd, cnt_even}};
  transformation_matrix =
      power(transformation_matrix, 1LL * n * m, matrix_multiplier);
  Matrix initial = {{1, 0}, {0, 0}};
  Matrix res = matrix_multiplier(initial, transformation_matrix);
  if ((n & m & 1) == 1) {
    cout << (res[0][0] + res[0][1]) % MOD << endl;
  } else {
    cout << res[0][0] << endl;
  }
  return 0;
}