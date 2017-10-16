#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  set<int> st;

  cout << 1 << ' ';

  int last = n;

  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;

    st.insert(x);

    while (st.count(last) != 0) {
      st.erase(last);
      --last;
    }

    cout << st.size() + 1 << ' ';
  }

  return 0;
}
