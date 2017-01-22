#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int perm[N];

bool vis[N];

int n;

void Go(int x) {
  if (vis[x]) return;
  vis[x] = true;
  Go(perm[x]);
}

int GetCycles() {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    Go(i);
    ++res;
  }
  if (res == 1) --res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> perm[i];
  }

  bool odd = 0;

  for (int i = 1; i <= n; ++i) {
    bool x;
    cin >> x;
    odd ^= x;
  }

  int res = !odd;
  res += GetCycles();
  cout << res;
}
