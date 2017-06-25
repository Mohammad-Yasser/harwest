#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  stack<int> st;
  int res = 0;
  int curr = 1;

  for (int i = 0; i < 2 * n; ++i) {
    string s;
    cin >> s;

    if (s == "remove") {
      if (st.empty() || st.top() == curr) {
        if (!st.empty()) {
          st.pop();
        }
      } else {
        ++res;
        st = stack<int>();
      }
      ++curr;
    } else {
      int x;
      cin >> x;
      st.push(x);
    }
  }

  cout << res;
}
