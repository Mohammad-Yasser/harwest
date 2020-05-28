#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

const int N = 1003;

template <typename Long>
struct Fraction {
  Long num = 0, den = 1;
  Fraction(Long num = 0, Long den = 1) : num(num), den(den) { normalize(); }
  void normalize() {
    Long g = __gcd(num, den);
    num /= g, den /= g;
  }
  Fraction operator*(const Fraction& other) const {
    Fraction res = other;
    res.num *= num;
    res.den *= den;
    res.normalize();
    return res;
  }
  Fraction operator/(const Fraction& other) const {
    return (*this) * Fraction(other.den, other.num);
  }
  Fraction operator+(const Fraction& other) const {
    Fraction res = other;
    Long lcm = res.den / __gcd(res.den, den) * den;
    res.num *= lcm / res.den;
    res.num += lcm / den * num;
    res.den = lcm;
    res.normalize();
    return res;
  }
  Fraction operator-(const Fraction& other) const {
    Fraction res = other * Fraction(-1);
    return (*this) + res;
  }
  bool operator==(const Fraction& other) const {
    // Must be normalized.
    return num == other.num && den == other.den;
  }

  bool isNegative() const { return (num < 0) ^ (den < 0); }
  Fraction reciprocal() const {
    Fraction res(den, num);
    res.normalize();
    return res;
  }

  bool operator<(const Fraction& other) const {
    if ((*this) == other) return false;
    if (den == 0) return false;
    if (other.den == 0) return true;
    if (isNegative() && !other.isNegative()) return true;
    if (!isNegative() && other.isNegative()) return false;
    if (isNegative() && other.isNegative())
      return other * Fraction(-1) < (*this) * Fraction(-1);

    if (num / den > other.num / other.den) return false;
    if (num / den < other.num / other.den) return true;

    Fraction a = Fraction(den, num % den);
    Fraction b = Fraction(other.den, other.num % other.den);

    return b < a;

    return num * other.den < den * other.num;
  }
  friend Fraction abs(const Fraction& x) {
    Fraction res = x;
    res.num = abs(res.num), res.den = abs(res.den);
    return res;
  }

  friend ostream& operator<<(ostream& os, const Fraction& f) {
    return os << f.num << "/" << f.den << " : " << fixed << setprecision(30)
              << 1.0L * f.num / f.den;
  }
};

Fraction<Long> getAvg(Long n, int h, int c) {
  return Fraction(n / 2 * c + (n + 1) / 2 * h, n);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;
  vector<Long> candidates;
  while (t--) {
    Long h, c;
    Fraction<Long> tmp;
    cin >> h >> c >> tmp.num;
    Long low = 0, high = round(1e7 + 1), ans = 0;
    while (low <= high) {
      Long mid = (low + high) / 2;
      Fraction avg = getAvg(2 * mid + 1, h, c);
      if (avg < tmp) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    candidates.clear();
    candidates.emplace_back(2);
    for (int i = -1; i <= 0; ++i) {
      if (2 * (ans + i) + 1 > 0) candidates.emplace_back(2 * (ans + i) + 1);
    }
    sort(all(candidates));
    Fraction best = Fraction(LLONG_MAX);
    Long res = 1;
    for (Long n : candidates) {
      Fraction avg = getAvg(n, h, c);
      Fraction diff = abs(avg - tmp);
      if (diff < best) {
        best = diff;
        res = n;
      }
    }
    cout << res << endl;
  }

  return 0;
}