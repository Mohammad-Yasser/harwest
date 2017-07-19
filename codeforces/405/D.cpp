#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int S = round(1e6) + 1;
bool used[S];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  Long sum = 0;
  while (n--) {
    int x;
    cin >> x;
    sum += x - 1;
    used[x] = true;
  }

  int cnt_s = 0;

  vector<int> res;

  for (int i = 1; i < S; ++i) {
    if (used[i]) {
      if (!used[S - i]) {
        res.push_back(S - i);
      } else {
        ++cnt_s;
      }
    }
  }

  cnt_s /= 2;

  for (int i = 1; i < S && cnt_s > 0; ++i) {
    if (!used[i] && !used[S - i]) {
      res.push_back(i);
      res.push_back(S - i);
      --cnt_s;
    }
  }

  cout << res.size() << '\n';

  for (int x : res) {
    cout << x << ' ';
    sum -= S - 1 - x;
  }
  cout << endl;
  assert(sum == 0);

}
