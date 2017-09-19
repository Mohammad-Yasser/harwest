#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
//  freopen("test.in", "r", stdin);
#else
//#define endl '\n'
#endif

  int n;
  cin >> n;

  cout << "? " << string(n, '0') << endl;

  int ones;
  cin >> ones;

  int begin = 0, end = n - 1, mid;

  int r0 = -1, r1 = -1;

  while (r1 == -1 || r0 == -1) {
    string q = string(n, '0');
    mid = (begin + end) / 2;
    for (int i = begin; i <= mid; ++i) {
      q[i] = '1';
    }
    cout << "? " << q << endl;
    int a;
    cin >> a;

    int sz = (mid - begin + 1);

    int x = (ones + sz - a) / 2;

    if (r1 == -1) {
      if (x == sz) {
        r1 = begin;
        continue;
      }
      if (x > 0) {
        end = mid;
      } else {
        r0 = begin;
        begin = mid + 1;
      }
    } else {
      if (x == 0) {
        r0 = begin;
        break;
      }
      if (x == sz) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
  }

  cout << "! " << ++r0 << ' ' << ++r1 << endl;

}

