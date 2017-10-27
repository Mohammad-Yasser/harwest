#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;

int to[N];

vector<int> lengths;

bool vis[N];

int go(int node) {
  if (vis[node]) return 0;
  vis[node] = true;
  return 1 + go(to[node]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> to[i];
  }

  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    lengths.push_back(go(i));
  }

  sort(lengths.rbegin(), lengths.rend());

  Long cnt;
  if (lengths.size() == 1) {
    cnt = n;
  } else {
    cnt = lengths[0] + lengths[1];
  }

  cnt *= cnt;

  for (int i = 2 ; i < lengths.size() ; ++i) {
    cnt += 1LL * lengths[i] * lengths[i];
  }

  cout << cnt;

}

