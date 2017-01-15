#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10004;

int par[N];

void Init() {
  for (int i = 0; i < N; ++i) {
    par[i] = i;
  }
}

int GetRoot(int x) {
  if (par[x] == x) return x;
  return par[x] = GetRoot(par[x]);
}

void Join(int x, int y) {
  y = GetRoot(y);
  x = GetRoot(x);
  par[x] = y;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  Init();
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Join(i, x);
  }

  set<int> sets;
  for (int i = 1; i <= n; ++i) {
    sets.insert(GetRoot(i));
  }

  cout << sets.size();

}
