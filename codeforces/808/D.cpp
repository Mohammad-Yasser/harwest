#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e5 + 5;

int arr[N];

bool Check(Long a, Long b, const unordered_multiset<Long>& ms) {
  if ((a - b) & 1) return false;
  Long x = (a - b) / 2;
  /*
   * a - x == b + x
   * a - b == 2 x
   *
   */
  return ms.count(x) > 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  unordered_multiset<Long> left, right;
  left.reserve(2 * n);
  right.reserve(2 * n);

  left.max_load_factor(0.25);
  right.max_load_factor(0.25);

  Long sum_left = 0, sum_right = 0;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    sum_right += arr[i];
    right.insert(arr[i]);
  }

  for (int i = 0; i < n; ++i) {
    right.erase(right.find(arr[i]));
    left.insert(arr[i]);

    sum_left += arr[i];
    sum_right -= arr[i];

    if (sum_left == sum_right) {
      cout << "YES";
      return 0;
    }

    if (sum_left > sum_right && Check(sum_left, sum_right, left)) {
      cout << "YES";
      return 0;
    }

    if (sum_left < sum_right && Check(sum_right, sum_left, right)) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";

}
