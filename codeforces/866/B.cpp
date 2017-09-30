#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 1e5 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, s;
  cin >> n >> s;

  vector<pair<Long, Long>> d(n);
  Long sum_all = 0;
  Long sum_pa = 0;
  Long curr_happiness = 0;

  for (int i = 0; i < n; ++i) {
    Long tot, a, b;
    cin >> tot >> a >> b;

    d[i] = {a - b , tot};
    sum_all += tot;
    curr_happiness += tot * b;
    if (a > b) {
      sum_pa += tot;
    }
  }

  Long pizzas = (sum_all + s - 1) / s;

  sort(d.begin(), d.end());

  Long res = curr_happiness;

  Long a = sum_pa / s;
  Long a_slices = a * s;
  Long b_slices = pizzas * s - sum_all - a * s;

  Long b = min(pizzas, a + 1);

  for (; a <= b; ++a, a_slices += s, b_slices -= s) {
    if (d.empty()) break;
    if (d.back().first < 0) break;

    while (!d.empty() && (d.back().first > 0 && a_slices > 0 || b_slices < 0)) {
      Long x = min(a_slices, d.back().second);

      if (d.back().first < 0) {
        x = min(x, -b_slices);
      }

      curr_happiness += x * d.back().first;
      a_slices -= x;
      d.back().second -= x;
      b_slices += x;

      if (d.back().second == 0) {
        d.pop_back();
      }
    }

    res = max(res, curr_happiness);
  }

  cout << res;
}
