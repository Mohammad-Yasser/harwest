#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int prices[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++prices[x];
  }
  for (int i = 1; i < N; ++i) prices[i] += prices[i - 1];

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << prices[min(x,N-1)] << '\n';
  }
}