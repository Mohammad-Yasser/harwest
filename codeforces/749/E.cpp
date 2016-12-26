#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
struct BIT {
  vector<T> v;
  BIT(int s) {
    Resize(s);
  }
  void Clear() {
    v.clear();
  }
  BIT() {
  }
  void Resize(int s) {
    s = 1 << (int) ceil(log2(1.0 * (s + 1)));
    v.resize(s);
  }
  T Get(int i) {
    i++;
    T r = 0;
    while (i) {
      r += v[i - 1];
      i -= i & -i;
    }
    return r;
  }
  void Add(int i, T val) {
    i++;
    while (i <= (int) v.size()) {
      v[i - 1] += val;
      i += i & -i;
    }
  }
  int Find(T val) { // Find element at index ind.
    int s = 0;
    int m = v.size() >> 1;
    while (m) {
      if (v[s + m - 1] < val) val -= v[(s += m) - 1];
      m >>= 1;
    }
    return s;
  }
};

const int N = 100005;
int arr[N];
int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  cin >> n;
  BIT<ll> bit_segments(N);
  BIT<int> bit_elements(N);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  ll curr_inversions_segments = 0;
  ll total_inversions_segments = 0;

  ll cnt_inversions_elements = 0;

  for (int i = n - 1; i >= 0; --i) {
    curr_inversions_segments += bit_segments.Get(arr[i]);
    total_inversions_segments += curr_inversions_segments;
    bit_segments.Add(arr[i], n - i);

    cnt_inversions_elements += bit_elements.Get(arr[i]);
    bit_elements.Add(arr[i], 1);
  }

  double expected_inversions = 0;
  for (int len = 1; len <= n; ++len) {
    expected_inversions += 1LL * len * (len - 1) * (n - len + 1);
  }

  expected_inversions /= 4;

  double res = cnt_inversions_elements
    + (-total_inversions_segments + expected_inversions)
      / (1LL * n * (n + 1) / 2);


  cout << fixed << setprecision(9) << res << endl;

}
