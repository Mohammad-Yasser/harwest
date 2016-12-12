#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000006;
int arr[N];
int cnt_multiples[N];
int cnt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] < N) {
      ++cnt[arr[i]];
    }
  }

  for (int i = 1; i < N; ++i) {
    for (int multiple = i; multiple < N; multiple += i) {
      cnt_multiples[multiple] += cnt[i];
    }
  }

  int mxi = 1;

  for (int i = 1; i <= m; ++i) {
    if (cnt_multiples[i] > cnt_multiples[mxi]) {
      mxi = i;
    }
  }

  cout << mxi << ' ' << cnt_multiples[mxi] << endl;
  for (int i = 0; i < n; ++i) {
    if (mxi % arr[i] == 0) {
      cout << i + 1 << ' ';
    }
  }

}
