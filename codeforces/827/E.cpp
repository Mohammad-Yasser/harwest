#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef vector<int> Polynomial;

typedef double Double;

struct Complex {
  Double real, imag;
  Complex() :
    real(0), imag(0) {
  }
  Complex(Double n) :
    real(n), imag(0) {
  }
  Complex(Double r, Double i) :
    real(r), imag(i) {
  }
  Complex operator +(Complex b) {
    return Complex(real + b.real, imag + b.imag);
  }
  Complex operator +=(Complex b) {
    real += b.real, imag += b.imag;
    return *this;
  }
  Complex operator -(Complex b) {
    return Complex(real - b.real, imag - b.imag);
  }
  Complex operator *(Complex b) {
    return Complex(real * b.real - imag * b.imag, real * b.imag + imag * b.real);
  }
  Complex operator /(Double n) {
    return Complex(real / n, imag / n);
  }
  Complex operator *=(Complex b) {
    return (*this) = (*this) * b;
  }
  Complex operator /=(Double n) {
    return (*this) = (*this) / n;
  }
};

namespace FFTSolver {
const int MAXN = 1 << 20;

void fft(vector<Complex>& a, int n, int invert) {
  static Double PI = 2 * acos((Double) 0);
  for (int i = 1, j = 0; i < n; i++) {
    for (int s = n; j ^= s >>= 1, ~j & s;)
      ;
    if (i < j) swap(a[i], a[j]);
  }
  for (int m = 1; m < n; m <<= 1) {
    Double p = PI / m * (invert ? -1 : 1);
    Complex w = Complex(cos(p), sin(p));
    for (int i = 0; i < n; i += m << 1) {
      Complex unit = 1;
      for (int j = 0; j < m; j++) {
        Complex& x = a[i + j + m], &y = a[i + j], t = unit * x;
        x = y - t;
        y = y + t;
        unit *= w;
      }
    }
  }
  if (invert) for (int i = 0; i < n; i++)
    a[i] /= n;
}

Polynomial multiply(const Polynomial& a, const Polynomial& b) {
  int na = a.size();
  int nb = b.size();

  static vector<Complex> fa(MAXN << 1), fb(MAXN << 1);
  int n = 1;
  while (n < na + nb - 1)
    n <<= 1;
  for (int i = 0; i < n; i++)
    fa[i] = fb[i] = Complex(0);
  for (int i = 0; i < na; i++)
    fa[i] = Complex(a[i]);
  for (int i = 0; i < nb; i++)
    fb[i] = Complex(b[i]);
  fft(fa, n, 0);
  fft(fb, n, 0);
  for (int i = 0; i < n; i++)
    fa[i] *= fb[i];
  fft(fa, n, 1);

  Polynomial res(n);
  for (int i = 0; i < n; i++)
    res[i] = (fa[i].real + 0.5);
  return res;
}
}

void print(Polynomial p) {
  cout << "Size: " << p.size() << endl;
  for (int x : p) {
    cout << x << ' ';
  }
  cout << endl;
}

vector<int> getValid(const vector<bool>& invalid) {
  int n = invalid.size() - 1;
  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    bool valid = true;
    for (int j = i; j <= n && valid; j += i) {
      valid &= !invalid[j];
    }
    if (valid) {
      res.push_back(i);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    Polynomial v(n), k(n);
    Polynomial rev_v(n), rev_k(n);

    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
      v[i] = rev_v[n - 1 - i] = (s[i] == 'V');
      k[i] = rev_k[n - 1 - i] = (s[i] == 'K');
    }

    Polynomial v_rev_k = FFTSolver::multiply(v, rev_k);

    vector<bool> invalid(n + 1, false);

    for (int i = 0; i < v_rev_k.size(); ++i) {
      int d = i - n + 1;
      if (d > n) break;
      if (v_rev_k[i] == 0) continue;

      invalid[abs(d)] = true;
    }

    auto valid = getValid(invalid);

    cout << valid.size() << '\n';
    for (int x : valid) {
      cout << x << ' ';
    }
    cout << '\n';

  }

}
