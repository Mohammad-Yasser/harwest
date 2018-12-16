//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse4.1,sse4.2,ssse3,sse3,sse2,sse,avx")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 1e5 + 5;

vector<int> v[N];
int a[N];
int b[N];

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
    cin >> a[i];
    a[i] = n - a[i];
    v[a[i]].push_back(i);
  }

  int last = 0;

  for (int i = 1; i <= n; ++i) {
    if (v[i].size() % i != 0) {
      cout << "Impossible" << endl;
      return 0;
    }
    for (int j = 0; j < v[i].size(); ++j) {
      if (j % i == 0) {
        ++last;
      }
      b[v[i][j]] = last;
    }
  }

  cout << "Possible" << endl;
  for (int i = 1 ; i <= n ; ++i) {
    cout << b[i] << " ";
  }

}
