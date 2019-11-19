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

const int N = 1e6 + 5;
int arr[N];
int n;
Long sum;

vector<Long> getPrimeFactors(Long x) {
  vector<Long> res;
  for (Long i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      res.push_back(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x != 1) {
    res.emplace_back(x);
  }
  return res;
}

Long solve(const vector<int>& v) {
  Long curr_res = 0, curr_sum = 0;
  for (int i = 0; i < v.size(); ++i) {
    curr_res += 1LL * i * v[i];
    curr_sum += v[i];
  }
  Long res = curr_res;
  for (int i = 1; i < v.size(); ++i) {
    curr_sum -= 2 * v[i - 1];
    curr_res -= curr_sum;
    res = min(res, curr_res);
  }
  return res;
}

Long solve(Long k) {
  vector<int> v;
  Long curr_sum = 0;
  Long res = 0;
  for (int i = 0; i < n; ++i) {
    if (curr_sum + arr[i] < k) {
      curr_sum += arr[i];
      v.emplace_back(arr[i]);
    } else {
      v.emplace_back(k - curr_sum);
      res += solve(v);
      int x = (arr[i] - (k - curr_sum)) % k;
      v.clear();
      v.emplace_back(x);
      curr_sum = x;
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
    cin >> arr[i];
    sum += arr[i];
  }

  auto primes = getPrimeFactors(sum);
  if (primes.empty()) {
    cout << -1 << endl;
    return 0;
  }

  Long res = LLONG_MAX / 2;

  for (auto prime : primes) {
    res = min(res, solve(prime));
  }

  cout << res << endl;

}
