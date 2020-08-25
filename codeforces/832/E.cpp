#ifndef Local
#pragma GCC optimize("Ofast,fast-math")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << int(x) << " ";
  }
  return os;
}

const int MOD = round(1e9 + 7);

int power(int base, int p, int MOD = MOD) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * base % MOD;
  }
  return res;
}

int mod_inverse[] = {0, 1, 3, 2, 4, 0, 1, 3, 2, 4};

using Row = vector<char>;
using Matrix = vector<Row>;

inline bool isZero(const Row& row) { return count(all(row), 0) == sz(row); }

template <class T, class V>
T subMod(T x, V y, int mod) {
  if (x < y) return x - y + mod;
  return x - y;
}

Row subMultiple(const Row& a, const Row& b, int multiple, int mod) {
  Row res = a;
  for (int i = 0; i < sz(a); ++i) {
    res[i] = (res[i] - b[i] * multiple) % mod;
  }
  return res;
}

Matrix getREF(const Matrix& mat, int mod, int& rank) {
  if (mat.empty()) return mat;
  int n = sz(mat);     // no. of vectors.
  int m = sz(mat[0]);  // no. of columns.
  Matrix res = mat;
  rank = 0;
  for (int row = 0, col = 0; row < n && col < m; ++col) {
    for (int i = row; i < n; ++i) {
      if (res[i][col] != 0) {
        swap(res[row], res[i]);
        break;
      }
    }
    if (res[row][col] == 0) continue;
    ++rank;
    for (int i = row + 1; i < n; ++i) {
      if (res[i][col] == 0) continue;
      auto multiple = res[i][col] * mod_inverse[res[row][col] + mod];
      res[i] = subMultiple(res[i], res[row], multiple, mod);
    }
    ++row;
  }
  return res;
}

bool covered(const Matrix& rref, Row vctr, int mod) {
  int n = sz(rref);
  int m = sz(vctr);
  int curr_col = 0;
  int first_col = 0;

  for (int row = 0; row < n && !isZero(rref[row]); ++row) {
    while (rref[row][first_col] == 0) ++first_col;
    while (curr_col < m && vctr[curr_col] == 0) ++curr_col;
    if (first_col > curr_col) return false;
    if (first_col < curr_col) continue;
    int multiple = vctr[curr_col] * mod_inverse[rref[row][curr_col] + mod];
    vctr = subMultiple(vctr, rref[row], multiple, mod);
  }
  return isZero(vctr);
}

int n, m;

inline Row parse(const string& s) {
  Row res(m);
  for (int i = 0; i < m; ++i) {
    res[i] = s[i] - 'a';
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> m;

  vector<Row> mat(n);
  for (auto& row : mat) {
    static string s;
    cin >> s;
    row = parse(s);
  }
  int mod = 5;
  int rank = 0;
  auto rref = getREF(mat, mod, rank);
  int redundant = n - rank;
  int res = power(mod, redundant);

  int q;
  cin >> q;

  while (q--) {
    static string s;
    cin >> s;
    Row row = parse(s);
    if (covered(rref, row, mod)) {
      cout << res << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}