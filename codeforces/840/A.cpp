#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int main() {
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  vector<int> a(n);
  vector<pair<int, int>> b(n);

  for (auto& x : a) {
    cin >> x;
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i].first;
    b[i].second = i;
  }

  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());

  for (int i = 0 ; i < n ; ++i) {
    b[i].first = a[i];
    swap(b[i].first , b[i].second);
  }

  sort(b.begin() , b.end());

  for (auto& x : b) {
    cout << x.second << ' ';
  }

  return 0;
}
