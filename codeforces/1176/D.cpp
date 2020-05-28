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
typedef double Double;

const int N = 2750133;

int cnt[N];
int largest_div[N];
vector<int> primes;
void build() {
  for (int i = 2; i < N; ++i) {
    if (largest_div[i] == 0) {
      primes.emplace_back(i);
    }
    for (int j = 2 * i; j < N; j += i) {
      largest_div[j] = i;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  build();

  int n;
  cin >> n;

  vector<int> b(2 * n);

  for (int& x : b) {
    cin >> x;
    ++cnt[x];
  }

  vector<int> a;

  for (int i = N - 1; i > 0; --i) {
    while (cnt[i] != 0) {
      --cnt[i];
      if (largest_div[i] == 0) {
        int pos = lower_bound(all(primes), i) - begin(primes) + 1;
        a.emplace_back(pos);
        --cnt[pos];
      } else {
        a.emplace_back(i);
        --cnt[largest_div[i]];
      }
    }
  }

  for (int x : a) {
    cout << x << endl;
  }

  return 0;
}