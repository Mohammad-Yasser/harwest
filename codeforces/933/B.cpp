#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

const int N = 2e3 + 3;

vector<int> sol;
int k;

void solve(Long p) {
  if (p == 0) {
    cout << sol.size() << endl;
    for (int x : sol) {
      cout << x << " ";
    }
    exit(0);
  }
  for (int i = 0; i < k; ++i) {
    if ((i - p) % k == 0) {
      sol.push_back(i);
      solve((i - p) / k);
      sol.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  Long p;
  cin >> p >> k;

  solve(p);

  cout << -1;

}

