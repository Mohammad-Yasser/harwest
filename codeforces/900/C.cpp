#include <bits/stdc++.h>

using namespace std;
#define popCnt(x) (__builtin_popcount(x))

const int N = 1e5 + 5;

bool is_rec[N];
int cnt[N];

int arr[N];

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

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    st.insert(arr[i]);
    if (arr[i] == *st.rbegin()) {
      is_rec[arr[i]] = true;
    } else {
      int tmp = *st.rbegin();
      st.erase(tmp);
      if (arr[i] == *st.rbegin()) {
        ++cnt[tmp];
      }
      st.insert(tmp);
    }
  }

  int res = -1e7, best = 1;
  for (int i = 1; i <= n; ++i) {
    int tmp = cnt[i] - is_rec[i];
    if (tmp > res) {
      res = tmp;
      best = i;
    }
  }

  cout << best;

}
