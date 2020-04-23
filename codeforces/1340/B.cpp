#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

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

const int N = 2003;
const int A = 10;
int n, k;

int memo[N][N];
vector<string> numbers = {"1110111", "0010010", "1011101", "1011011",
                          "0111010", "1101011", "1101111", "1010010",
                          "1111111", "1111011"};

int need[N][A];

int cnt_diff(const string& a, const string& b) {
  int res = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == b[i]) continue;
    if (a[i] == '1') {
      return -1;
    }
    ++res;
  }
  return res;
}

bool solve(int ind, int k) {
  if (k < 0) return false;
  if (ind == n) return (k == 0);
  int& res = memo[ind][k];
  if (res != -1) return res;
  for (int i = A - 1; i >= 0; --i) {
    if (need[ind][i] == -1) continue;
    if (solve(ind + 1, k - need[ind][i])) return res = true;
  }
  return res = false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < A; ++j) {
      need[i][j] = cnt_diff(s, numbers[j]);
    }
  }

  memset(memo, -1, sizeof memo);

  if (!solve(0, k)) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = A - 1; j >= 0; --j) {
      if (need[i][j] == -1) continue;
      if (solve(i + 1, k - need[i][j])) {
        cout << char('0' + j);
        k -= need[i][j];
        break;
      }
    }
  }
  cout << endl;

  return 0;
}
