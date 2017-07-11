#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ' ' << x << endl;

typedef long long Long;

const int N = 2e6 + 5;


int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  string s(N, '?');
  set<int> empty;
  for (int i = 0; i < N; ++i) {
    empty.insert(i);
  }

  int n;
  cin >> n;

  int size = 0;

  for (int i = 0; i < n; ++i) {
    string curr;
    cin >> curr;

    int cnt;
    cin >> cnt;

    while (cnt--) {
      int x;
      cin >> x;
      --x;

      size = max(size, x + (int) curr.size());

      int j = x;
      while (j < x + curr.size()) {
        s[j] = curr[j - x];
        empty.erase(j);
        j = *empty.lower_bound(j + 1);
      }
    }

  }

  for (int i = 0; i < size; ++i) {
    if (s[i] == '?') {
      s[i] = 'a';
    }
    cout << s[i];
  }

  return 0;
}
