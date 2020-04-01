#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main() {
  ios_base::sync_with_stdio(false);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> colors(n);
    map<int, int> mp;
    for (int& color : colors) {
      int x;
      cin >> x;
      for (int p : primes) {
        if (x % p == 0) {
          color = p;
          if (mp[p] == 0) {
            mp[p] = mp.size();
          }
          break;
        }
      }
    }
    cout << mp.size() << endl;
    for (int color : colors) {
      cout << mp[color] << " ";
    }
    cout << endl;
  }
  return 0;
}
