#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 5201;
bitset<N> rows[N], cols[N];
int n;

bool check(int x) {
  if (n % x != 0) return false;
  for (int i = 0; i < n; ++i) {
    int j = i / x * x;
    if (rows[i] != rows[j]) return false;
    if (cols[i] != cols[j]) return false;
  }
  return true;
}

int hexToDec(char c) {
  if (isdigit(c)) return c - '0';
  return 10 + c - 'A';
}

vector<bool> decode(const string& s) {
  vector<bool> res;
  for (char c : s) {
    int x = hexToDec(c);
    for (int i = 3; i >= 0; --i) {
      res.push_back((x >> i) & 1);
    }
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

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    auto res = decode(s);
    for (int j = 0; j < n; ++j) {
      rows[i][j] = cols[j][i] = res[j];
    }
  }

  for (int x = n; x > 0; --x) {
    if (check(x)) {
      cout << x << endl;
      return 0;
    }
  }
  assert(false);
  cout << -1 << endl;
}
