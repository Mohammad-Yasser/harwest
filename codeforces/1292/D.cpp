#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5003;

int fact_cnt_prime_factors[N][N];
int highest_prime_factor[N];
int total_cnt[N];

vector<int> getPrimeFactors(int x) {
  vector<int> res;
  for (int i = 2; i * i <= x; ++i) {
    while (x % i == 0) {
      res.emplace_back(i);
      x /= i;
    }
  }
  if (x != 1) res.emplace_back(x);
  return res;
}

void buildPFC() {
  for (int i = 2; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      fact_cnt_prime_factors[i][j] = fact_cnt_prime_factors[i - 1][j];
    }
    total_cnt[i] = total_cnt[i - 1];

    auto prime_factors = getPrimeFactors(i);
    total_cnt[i] += prime_factors.size();

    for (int x : prime_factors) {
      ++fact_cnt_prime_factors[i][x];
    }

    highest_prime_factor[i] = N;
  }
}

int getHighestPrimeFactor(int x) {
  int& res = highest_prime_factor[x];
  while (res > 1 && fact_cnt_prime_factors[x][res] == 0) {
    --res;
  }
  return res;
}

int cnt_fragments_with_highest_prime_factor[N];
int cnt_fragments[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  buildPFC();

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt_fragments[x];
  }

  Long curr_res = 0;

  for (int i = 0; i < N; ++i) {
    curr_res += 1LL * total_cnt[i] * cnt_fragments[i];
  }

  do {
    memset(cnt_fragments_with_highest_prime_factor, 0,
      sizeof cnt_fragments_with_highest_prime_factor);

    pair<int, int> mx = { -1, -1 };
    for (int i = 2; i < N; ++i) {
      int highest_prime_factor = getHighestPrimeFactor(i);
      cnt_fragments_with_highest_prime_factor[highest_prime_factor] +=
        cnt_fragments[i];
      mx = max(mx,
        make_pair(cnt_fragments_with_highest_prime_factor[highest_prime_factor],
          highest_prime_factor));
    }

    if (mx.second > 1 && mx.first > n - mx.first) {
      curr_res -= 2 * mx.first - n;
      for (int i = 2; i < N; ++i) {
        int highest_prime_factor = getHighestPrimeFactor(i);
        if (highest_prime_factor != mx.second) {
          cnt_fragments[i] = 0;
        } else {
          --fact_cnt_prime_factors[i][mx.second];
        }
      }

    } else
      break;

  } while (true);

  cout << curr_res << endl;
}
