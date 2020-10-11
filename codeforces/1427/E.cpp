#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
typedef long long Long;
typedef double Double;

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
    os << x << " ";
  }
  return os;
}

const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(RANDOM);

struct Op {
  Long x, y;
  char op;
  Op(Long x, Long y, char op) : x(x), y(y), op(op) {}
};

vector<Op> res;
const Long OO = 5e18;
void addLeftShifts(Long x) {
  for (int i = 0; (2LL << i) < OO / x; ++i) {
    res.emplace_back((1LL << i) * x, (1LL << i) * x, '+');
  }
}

void formMultiple(Long x, Long m) {
  Long curr = 0;
  for (int i = 0; (2LL << i) < OO / x; ++i) {
    if ((m >> i) & 1) {
      res.emplace_back((1LL << i) * x, curr, '+');
      curr += (1LL << i) * x;
    }
  }
}

/* Source:
  https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/euclid.h

  Finds two integers x and y, such that ax+by=gcd(a,b).
  If a and b are coprime, then x is the inverse of a % b.
*/
Long egcd(Long a, Long b, Long& x, Long& y) {
  if (b) {
    Long d = egcd(b, a % b, y, x);
    return y -= a / b * x, d;
  }
  return x = 1, y = 0, a;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long x;
  cin >> x;
  Long orig_x = x;
  res.emplace_back(x, x, '^');
  addLeftShifts(x);
  int lg = __lg(x);
  res.emplace_back(x << lg, x, '^');
  Long y = (x << lg) ^ x;
  addLeftShifts(y);
  Long a, b;
  egcd(x, y, a, b);

  formMultiple(x, abs(a));
  formMultiple(y, abs(b));
  x *= abs(a), y *= abs(b);
  if ((x ^ y) != 1) {
    res.emplace_back(x, orig_x, '+');
    res.emplace_back(y, orig_x, '+');
    x += orig_x, y += orig_x;
  }
  res.emplace_back(y, x, '^');
  cout << sz(res) << endl;
  for (auto& op : res) {
    cout << op.x << " " << op.op << " " << op.y << endl;
  }
  return 0;
}