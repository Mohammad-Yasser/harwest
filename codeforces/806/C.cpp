#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;
const Long OO = 1e13;

Long arr[N];
int n;

bool Check(int cnt) {
  int rem = n - cnt;
  int prev = cnt;

  for (Long i = 2; i < OO; i *= 2) {
    prev = min(prev, (int) count(arr, arr + n, i));
    rem -= prev;
  }

  return rem <= cnt;
}

int Solve() {
  int low = 1, high = count(arr, arr + n, 1), mid, ans = -1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (Check(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

bool Valid() {
  int cnt[40];
  cnt[0] = count(arr, arr + n, 1);
  Long last[cnt[0]];

  for (int i = 0; i < cnt[0]; ++i) {
    last[i] = 1;
  }

  unordered_set<Long> pw2;
  pw2.insert(1);
  vector<Long> rem;

  for (int x = 1; x < 40; ++x) {
    Long val = 1LL << x;
    pw2.insert(val);
    cnt[x] = min(cnt[x - 1], (int) count(arr, arr + n, val));
    for (int i = 0; i < cnt[x]; ++i) {
      last[i] = val;
    }
    int rem_x = count(arr, arr + n, val) - cnt[x];
    for (int i = 0; i < rem_x; ++i) {
      rem.push_back(val);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (pw2.count(arr[i]) == 0) {
      rem.push_back(arr[i]);
    }
  }

  sort(rem.begin(), rem.end());

  for (int i = 0; i < cnt[0]; ++i) {
    if (!rem.empty() && rem.back() > 2 * last[i]) {
      return false;
    }
    if (!rem.empty()) {
      rem.pop_back();
    }
  }

  return rem.empty();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  if (!Valid()) {
    cout << -1;
    return 0;
  }

  int first = Solve();
  int last = count(arr, arr + n, 1);

  for (int i = first; i <= last; ++i) {
    cout << i << ' ';
  }
}
