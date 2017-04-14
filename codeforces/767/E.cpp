#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

const int N = 1e5 + 5;
const int kNoteValue = 100;

int c[N];
int w[N];

int Floor(int x) {
  return x / 100;
}

int notes[N];
int coins[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    notes[i] += Floor(c[i]);
  }

  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    w[i] *= (kNoteValue - c[i] % kNoteValue) % kNoteValue;
  }

  set<pair<int, int>> pq;

  Long res = 0;

  for (int i = 0; i < n; ++i) {
    if (w[i] > 0) {
      pq.emplace(w[i], i);
    }

    m -= c[i] % kNoteValue;

    if (m < 0) {
      auto top = *pq.begin();
      pq.erase(pq.begin());

      m += kNoteValue;
      ++notes[top.second];
      res += top.first;
    }

  }

  cout << res << '\n';

  for (int i = 0; i < n; ++i) {
    cout << notes[i] << ' ' << max(0, c[i] - kNoteValue * notes[i]) << '\n';
  }

}
