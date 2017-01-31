#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
tuple<int, int, int> arr[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  int n, l, r;
  cin >> n >> l >> r;

  for (int i = 0; i < n; ++i) {
    cin >> get<1>(arr[i]);
    get<2>(arr[i]) = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(arr[i]);
  }
  sort(arr, arr + n);

  int last = INT_MIN;

  for (int i = 0; i < n; ++i) {
    b[get<2>(arr[i])] = max(last + 1 + get<1>(arr[i]), l);
    last = b[get<2>(arr[i])] - get<1>(arr[i]);
    if (b[get<2>(arr[i])] > r) {
      cout << -1;
      return 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << b[i] << ' ';
  }

}
