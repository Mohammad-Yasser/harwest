#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2e6 + 7;
const int SqrtN = sqrt(N) + 1;

int arr[N];

int n;
Long x, y;

int upperBound[N];
Long acc[N];

void build() {
  sort(arr, arr + n);
  arr[n] = 3 * N;
  int curr_ind = 0;
  for (int i = 0; i < N; ++i) {
    while (arr[curr_ind] <= i) {
      ++curr_ind;
    }
    upperBound[i] = curr_ind;
    if (i > 0) {
      acc[i] = arr[i] + acc[i - 1];
    }
  }
}

int getA(int s, int x, int y) {
  int a = s - x / y + 3;
  while (1LL * y * (s - a) < x && a > 0) {
    --a;
  }
  return max(a, 0);
}

Long calc(int g) {
  if (g > N / 2) return LLONG_MAX;

  Long res = 0;
  int last = 1;

  for (int i = g; i < N; i += g) {
    int curr = upperBound[i];
    int a = getA(i, x, y);
    int ind_a = max(last, upperBound[a]);
    ind_a = min(ind_a, curr);

    int use_x = ind_a - last;
    int use_y = curr - ind_a;

    res += 1LL * use_x * x;
    res += (1LL * i * use_y - (acc[curr - 1] - acc[ind_a - 1])) * y;

    last = curr;
  }

  return res;
}

bool not_prime[N];
vector<int> primes;

void sieve() {
  for (int i = 2; i < N; ++i) {
    if (not_prime[i]) continue;
    primes.push_back(i);
    for (int j = 2 * i; j < N; j += i) {
      not_prime[j] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n >> x >> y;
  ++n;
  for (int i = 1; i < n; ++i) {
    cin >> arr[i];
  }

  sieve();
  build();

  Long res = LLONG_MAX;

  for (int x : primes) {
    res = min(res, calc(x));
  }

  cout << res;

}
