#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ' ' << x << endl;

typedef long long Long;

int getMax(int r_plate, int r_table) {
  if (r_plate > r_table) return 0;
  int r_small = r_table - r_plate;
  if (r_plate > r_small) return 1;

  double angle = 2 * asin(1.0 * r_plate / r_small);

  return floor(2 * acos(-1) / angle + 1e-10);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, r_table, r_plate;
  cin >> n >> r_table >> r_plate;

  int mx = getMax(r_plate, r_table);
  cout << (n <= mx ? "YES" : "NO");

  return 0;
}
