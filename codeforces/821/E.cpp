#include <bits/stdc++.h>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

typedef long long Long;

typedef vector<int> Row;
typedef vector<Row> Matrix;

const int MOD = round(1e9 + 7);
const int MatrixLength = 16;

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

Matrix empty_matrix(int r, int c) {
  return Matrix(r, Row(c));
}

Matrix empty_matrix(int r) {
  return empty_matrix(r, r);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  Long k;
  cin >> k;

  MatrixMultiplier matrix_multiplier;

  Matrix res = identity_element(matrix_multiplier);

  while (n--) {
    Long a, b, c;
    cin >> a >> b >> c;
    b = min(k, b);

    Long l = b - a;

    Matrix tmp = empty_matrix(MatrixLength);

    for (int i = 0; i <= c; ++i) {
      for (int j = i - 1; j <= i + 1; ++j) {
        if (j < 0 || j > c) continue;
        tmp[i][j] = 1;
      }
    }

    tmp = power(tmp, l, matrix_multiplier);

    res = matrix_multiplier(res, tmp);
  }

  Matrix tmp = empty_matrix(MatrixLength, 1);

  tmp[0][0] = 1;

  res = matrix_multiplier(res, tmp);

  cout << res[0][0] << '\n';
}
