#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 101;

int nxt[N];

int b, d;
string a, c;

void build() {
  for (int i = 0; i < c.size(); ++i) {
    int curr = i;
    for (int j = 0; j < a.size(); ++j) {
      if (a[j] == c[curr % c.size()]) {
        ++curr;
      }
    }
    nxt[i] = curr;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> b >> d >> a >> c;
  build();

  int res = 0;
  int curr_in_c = 0;
  for (int i = 0; i < b; ++i) {
    int to = nxt[curr_in_c];
    res += to / c.size();
    to %= c.size();
    curr_in_c = to;
  }

  cout << res / d;
}
