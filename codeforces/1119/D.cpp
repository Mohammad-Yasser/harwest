#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;

Long s[N];
vector<Long> d;
vector<Long> accD;
int n;

void build() {
  sort(s, s + n);
  for (int i = 0; i + 1 < n; ++i) {
    d.push_back(s[i + 1] - s[i]);
  }
  d.push_back(2e18 + 5);
  sort(d.begin(), d.end());
  accD.push_back(0);
  for (int i = 0; i < d.size(); ++i) {
    accD.push_back(accD.back() + d[i]);
  }

}

Long query(Long k) {
  int ind = lower_bound(d.begin(), d.end(), k) - d.begin();
  Long res = accD[ind];
  res += (d.size() - ind) * k;
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
    cin >> s[i];
  }

  build();

  int q;
  cin >> q;

  while (q--) {
    Long l, r;
    cin >> l >> r;
    cout << query(r - l + 1) << " ";
  }

}

