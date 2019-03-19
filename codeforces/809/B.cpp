#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef unsigned long long Long;

const int N = 1e5 + 5;

bool ask(int x, int y) {
  cout << 1 << " " << x << " " << y << endl;
  string res;
  cin >> res;
  return res[0] == 'T';
}

int solve(int l, int r) {
  if (r < l) return 1;
  if (l == r) return l;
  int x = (l + r) / 2;
  int y = (l + r + 1) / 2;

  if (x == y) {
    ++y;
  }

  if (ask(x, y)) {
    return solve(l, x);
  }

  return solve(y, r);
}

int n;
bool valid(int x) {
  if (x != n && !ask(x, x + 1)) {
    return false;
  }
  if (x != 1 && !ask(x, x - 1)) {
    return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
//  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int k;
  cin >> n >> k;

  int a = solve(1, n);
  int b = solve(a + 1, n);
  int c = solve(1, a - 1);

  if (valid(b)) {
    cout << 2 << " " << a << " " << b << endl;
  } else {
    cout << 2 << " " << a << " " << c << endl;
  }

}

