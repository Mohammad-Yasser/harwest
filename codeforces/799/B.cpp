#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2e5 + 5;

vector<int> colors[4];

set<int> used;

int p[N];
int a[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < n; ++i) {
    colors[a[i]].push_back(p[i]);
    colors[b[i]].push_back(p[i]);
  }

  for (int i = 1; i < 4; ++i) {
    sort(colors[i].rbegin(), colors[i].rend());
  }

  int m;
  cin >> m;

  while (m--) {
    int c;
    cin >> c;

    while (!colors[c].empty() && used.count(colors[c].back())) {
      colors[c].pop_back();
    }

    if (colors[c].empty()) {
      cout << "-1 ";
      continue;
    }

    cout << colors[c].back() << ' ';
    used.insert(colors[c].back());
    colors[c].pop_back();
  }

}
