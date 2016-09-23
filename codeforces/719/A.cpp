#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  if (arr[n - 1] == 0) {
    cout << "UP";
    return 0;
  }
  if (arr[n - 1] == 15) {
    cout << "DOWN";
    return 0;
  }
  if (n == 1) {
    cout << -1;
    return 0;
  }

  if (arr[n - 2] < arr[n - 1]) {
    cout << "UP";
  } else {
    cout << "DOWN";
  }

  return 0;
}
