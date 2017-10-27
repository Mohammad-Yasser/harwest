#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2e5 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  Long res = 0;

  priority_queue<Long, vector<Long>, greater<Long>> pq;

  while (n--) {
    Long x;
    cin >> x;
    pq.push(x);
  }

  while (pq.size() > 1) {
    Long sum = 0;
    for (int i = 0; i < ((pq.size() & 1) ? 3 : 2) && !pq.empty(); ++i) {
      sum += pq.top();
      pq.pop();
    }
    res += sum;
    pq.push(sum);
  }

  cout << res;

}

