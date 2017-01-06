#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 101;

int arr[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("wa.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  int sum = 0;
  int non_zero = -1;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] != 0) {
      non_zero = i;
    }
    sum += arr[i];
  }


  if (non_zero == -1) {
    cout << "NO";
    return 0;
  }

  cout << "YES\n";

  if (sum != 0) {
    cout << "1\n1 " << n;
    return 0;
  }



  cout << "2\n1 " << non_zero << '\n' << non_zero + 1 << ' ' << n;


}
