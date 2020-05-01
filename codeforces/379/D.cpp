#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const int K = 51;

Long cnt[K];
char first[K];
char last[K];
int k;

bool check(char a, char c) { return a == 'A' && c == 'C'; }
int x;

bool valid() {
  for (int i = 3; i <= k; ++i) {
    cnt[i] = cnt[i - 2] + cnt[i - 1] + check(last[i - 2], first[i - 1]);
    if (cnt[i] > x) return false;
    last[i] = last[i - 1];
    first[i] = first[i - 2];
  }
  return cnt[k] == x;
}

int n, m;

int count(const string& x) {
  int res = 0;
  for (int i = 0; i + 1 < x.size(); ++i) {
    res += (x[i] == 'A' && x[i + 1] == 'C');
  }
  return res;
}

bool construct(string& a, int cnt, char first, char last) {
  a[0] = first, a.back() = last;
  int x = cnt;
  if (x > 0 && a[0] == 'A' && a.size() > 1 && a[1] == 'B') {
    a[1] = 'C';
    --x;
  }
  if (x > 0 && a[a.size() - 1] == 'C' && a.size() > 1 &&
      a[a.size() - 2] == 'B') {
    a[n - 2] = 'A';
    --x;
  }
  for (int i = 0; i + 1 < a.size() && x > 0; ++i) {
    if (a[i] == 'B' && a[i + 1] == 'B') {
      a[i] = 'A', a[i + 1] = 'C';
      --x;
    }
  }
  if (count(a) != cnt) return false;
  if (a[0] != first || a.back() != last) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> k >> x >> n >> m;

  for (cnt[1] = 0; cnt[1] <= n / 2; ++cnt[1]) {
    for (cnt[2] = 0; cnt[2] <= m / 2; ++cnt[2]) {
      for (first[1] = 'A'; first[1] <= 'C'; ++first[1]) {
        for (first[2] = 'A'; first[2] <= 'C'; ++first[2]) {
          for (last[1] = 'A'; last[1] <= 'C'; ++last[1]) {
            for (last[2] = 'A'; last[2] <= 'C'; ++last[2]) {
              if (!valid()) continue;
              string a(n, 'B'), b(m, 'B');
              if (construct(a, cnt[1], first[1], last[1]) &&
                  construct(b, cnt[2], first[2], last[2])) {
                cout << a << endl;
                cout << b << endl;
                return 0;
              }
            }
          }
        }
      }
    }
  }

  cout << "Happy new year!" << endl;

  return 0;
}
