#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int res = 0;

int child[N][2];
int parent[N];
int val[N];
int cnt[N];
map<int, int> compress;
int n;

void Compress() {
  for (int i = 1; i <= n; ++i) {
    compress[val[i]];
  }

  int curr = 0;

  for (auto& p : compress) {
    p.second = ++curr;
  }

  for (int i = 1; i <= n; ++i) {
    val[i] = compress[val[i]];
    ++cnt[val[i]];
  }

  for (int i = 1 ; i < N ; ++i) {
    cnt[i] += cnt[i - 1];
  }

}

void Solve(int node, int l, int r) {
  if (node == -1) {
    res += cnt[r] - cnt[l - 1];
    return;
  }

  if (l <= val[node] && val[node] <= r) {
    Solve(child[node][0], l, val[node] - 1);
    Solve(child[node][1], val[node] + 1, r);
    return;
  }

  Solve(child[node][(val[node] < l)], l, r);
}

int main() {
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
    for (int j = 0; j < 2; ++j) {
      cin >> child[i][j];
      if (child[i][j] != -1) {
        parent[child[i][j]] = i;
      }
    }
  }

  Compress();

  int root = 0;

  for (int i = 1; i <= n; ++i) {
    if (parent[i] == 0) {
      root = i;
    }
  }

  Solve(root, 1, N - 1);

  cout << res << endl;

  return 0;
}
