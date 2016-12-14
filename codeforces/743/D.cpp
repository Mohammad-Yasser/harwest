#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N = 200005;
int arr[N];

vector<int> adj[N];

ll max2 = LLONG_MIN, max1 = LLONG_MIN;

ll Solve(int node, int parent) {
  ll sum = arr[node];
  ll max_so_far = max1;
  for (int v : adj[node]) {
    if (v == parent) continue;
    sum += Solve(v, node);
  }
  if (max_so_far != LLONG_MIN) {
    max2 = max(max2, sum + max_so_far);
  }
  max1 = max(max1, sum);
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  Solve(0, -1);
  if (max2 == LLONG_MIN) {
    cout << "Impossible";
    return 0;
  }
  cout << max2;
}
