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

  set<string> st;

  while (n--) {
    string s;
    cin >> s;

    if (st.count(s)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

    st.insert(s);
  }

}
