#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef vector<Long> Row;
typedef vector<Row> Matrix;

const Long OO = 1.5e18;

struct MatrixMultiplier {
  int r;
  MatrixMultiplier(int r) :
    r(r) {
  }
  Matrix operator()(const Matrix& a, const Matrix& b) {
    int x = a.size(), y = b.size(), z = b[0].size();
    Matrix res(x, Row(z));
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < z; ++j) {
        for (int k = 0; k < y; ++k) {
          if (b[k][j] != 0 && a[i][k] > OO / b[k][j]) {
            res[i][j] = OO;
          } else {
            res[i][j] += min(1LL * a[i][k] * b[k][j], OO);
            res[i][j] = min(res[i][j], OO);
          }
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

void trimLeadingZeroes(vector<Long>& v) {
  auto it = v.begin();
  while (it != v.end() && *it == 0) {
    ++it;
  }
  v.erase(v.begin(), it);
}

int solveBF(const vector<Long>& v, Long k) {
  vector<Long> curr = v;
  int res = 0;
  while (curr.back() < k) {
    for (int i = 1; i < curr.size(); ++i) {
      curr[i] += curr[i - 1];
      curr[i] = min(curr[i], OO);
    }
    ++res;
  }
  return res;
}

Long solveBS(const vector<Long>& v, Long k) {
  Matrix transition = empty_matrix(v.size());
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v.size(); ++j) {
      transition[i][j] = (i <= j);
    }
  }
  MatrixMultiplier mat_mul(v.size());
  Matrix curr = empty_matrix(1, v.size());
  curr[0] = v;
  vector<Matrix> transition_powers;
  transition_powers.emplace_back(transition);
  for (int i = 0; i < 65; ++i) {
    transition_powers.emplace_back(
      mat_mul(transition_powers.back(), transition_powers.back()));
  }
  Long res = 0;
  for (int i = transition_powers.size() - 1; i >= 0; --i) {
    auto tmp = mat_mul(curr, transition_powers[i]);
    if (tmp[0].back() < k) {
      res += (1LL << i);
      curr = tmp;
    }
  }
  return res + 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  Long k;
  cin >> n >> k;

  vector<Long> v(n);
  for (auto& x : v) {
    cin >> x;
    if (x >= k) {
      cout << 0 << endl;
      return 0;
    }
  }

  trimLeadingZeroes(v);
  v.insert(v.begin(), 0);

  if (v.size() > 10) {
    cout << solveBF(v, k) << endl;
    return 0;
  }

  cout << solveBS(v, k) << endl;
  return 0;
}
