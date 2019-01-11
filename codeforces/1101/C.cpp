#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 2e5 + 5;

struct Segment {
  int id;
  int l, r;
  int res;
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
      auto& seg = segments[i];
      seg.id = i;
      cin >> seg.l >> seg.r;
    }

    sort(segments.begin(), segments.end(),
      [](const Segment& a , const Segment& b) {
        return make_pair(a.l , a.r) < make_pair(b.l , b.r);
      });

    int mx_r = segments[0].r;
    int border = -1;
    for (auto& seg : segments) {
      if (seg.l > mx_r) {
        border = seg.l;
        break;
      }
      mx_r = max(mx_r, seg.r);
    }

    if (border == -1) {
      cout << -1 << endl;
      continue;
    }

    sort(segments.begin(), segments.end(),
      [](const Segment& a , const Segment& b) {
        return a.id < b.id;
      });

    for (auto& seg : segments) {
      if (seg.l >= border) {
        cout << 2 << " ";
      } else {
        cout << 1 << " ";
      }
    }
    cout << endl;
  }

}
