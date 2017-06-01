#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int MX = 1e7 + 7;
const int N = 1e5 + 5;

int cnt[MX][2];

vector<int> adj[N];
int a[N];

bool parity;

void Dfs(int node, bool pr) {
  if (adj[node].empty()) {
    parity = pr;
  }

  ++cnt[a[node]][pr];

  for (int v : adj[node]) {
    Dfs(v, !pr);
  }
}

Long nC2(Long n) {
  return n * (n - 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  Dfs(1, 0);

  if (parity) {
    for (int i = 0; i < MX; ++i) {
      swap(cnt[i][0], cnt[i][1]);
    }
  }

  int xor_sum = 0;
  int cnt_odd = 0;
  int cnt_even = 0;

  for (int i = 0; i < MX; ++i) {
    if (cnt[i][0] & 1) {
      xor_sum ^= i;
    }

    cnt_odd += cnt[i][1];
    cnt_even += cnt[i][0];
  }

  Long res = 0;

  if (xor_sum == 0) {
    res += nC2(cnt_odd);
    res += nC2(cnt_even);
  }

  for (int i = 0; i < MX; ++i) {
    if (xor_sum == 0) {
      res += 1LL * cnt[i][0] * cnt[i][1];
    } else if ((i ^ xor_sum) < MX) {
      res += 1LL * cnt[i][0] * cnt[i ^ xor_sum][1];
    }
  }

  cout << res;

}
