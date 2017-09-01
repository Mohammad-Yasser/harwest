#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2e5 + 7;

deque<int> dq[N];
vector<pair<int, int>> tmp[N];

pair<int, int> ans[N];

vector<tuple<int, int, int>> vert;
vector<int> pos_x[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, w, h;
  cin >> n >> w >> h;

  for (int i = 0; i < n; ++i) {
    int g, p, t;
    cin >> g >> p >> t;
    if (g == 1) {
      tmp[t - p + N / 2].emplace_back(p, i);
    } else {
      vert.emplace_back(p, t, i);
    }
  }

  for (int i = 0; i < N; ++i) {
    auto& x = tmp[i];
    sort(x.begin(), x.end());

    for (auto& t : x) {
      dq[i].push_back(t.second);
    }
  }

  sort(vert.begin(), vert.end());

  for (auto& x : vert) {
    int p = get<0>(x);
    int t = get<1>(x);
    int ind = get<2>(x);
    int e = t - p + N / 2;

    auto& d = dq[e];
    d.push_front(ind);

    auto back = d.back();

    ans[back] = {w , p};
    d.pop_back();
  }

  for (int i = 0; i < N; ++i) {
    auto& x = tmp[i];
    auto& d = dq[i];

    for (auto t : x) {
      ans[d.front()] = {t.first,h};
      d.pop_front();
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }

}
