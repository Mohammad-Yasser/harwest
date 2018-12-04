#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2003;
const int K = round(1e6) / 2;

int arr[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    arr[i] += K;
  }

  cout << n + 1 << endl;

  cout << "1 " << n << " " << K << endl;

  for (int i = 1; i <= n; ++i) {
    cout << "2 " << i << " " << arr[i] - i << endl;
  }

}
