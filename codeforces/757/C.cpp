#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Component;

const int N = 1000006;
const int MOD = 1000000007;
Component comp[N];

int cnt[N];

int factorial[N];

void BuildFactorial() {
  factorial[0] = 1;
  for (int i = 1; i < N; ++i) {
    factorial[i] = 1LL * i * factorial[i - 1] % MOD;
  }
}

int n, m;

void BuildComponents() {
  for (int i = 1; i <= n; ++i) {
    int g;
    cin >> g;
    int gym[g];
    Component old_comp[g];
    for (int j = 0; j < g; ++j) {
      cin >> gym[j];
      old_comp[j] = comp[gym[j]];
      ++cnt[gym[j]];
    }

    map<pair<Component, int>, int> new_components;

    for (int j = 0; j < g; ++j) {
      new_components[ { comp[gym[j]], cnt[gym[j]] }];
    }
    int comp_id = 0;
    for (auto& comp : new_components) {
      comp.second = ++comp_id;
    }

    for (int j = 0; j < g; ++j) {
      comp[gym[j]] = {i,new_components[ {old_comp[j], cnt[gym[j]]}]};
    }

    for (int j = 0; j < g; ++j) {
      --cnt[gym[j]];
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("wa.txt", "w", stdout);
#endif

  BuildFactorial();

  cin >> n >> m;

  BuildComponents();

  map<Component, int> comp_cnt;

  for (int i = 1; i <= m; ++i) {
    ++comp_cnt[comp[i]];
  }

  int res = 1;

  for (auto &x : comp_cnt) {
    res = 1LL * res * factorial[x.second] % MOD;
  }
  cout << res;
}
