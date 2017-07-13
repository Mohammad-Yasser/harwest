#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 3e3;

int office;

int get(const vector<int>& people, const vector<int>& keys) {
  int res = 0;
  for (int i = 0; i < people.size(); ++i) {
    res = max(res, abs(people[i] - keys[i]) + abs(keys[i] - office));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k >> office;

  vector<int> people(n);
  for (int& x : people) {
    cin >> x;
  }

  sort(people.begin(), people.end());

  vector<int> keys(k);
  for (int& x : keys) {
    cin >> x;
  }

  sort(keys.begin(), keys.end());


  int res = INT_MAX;

  for (int i = 0; i + n <= k; ++i) {
    vector<int> used;
    for (int j = i; j < i + n; ++j) {
      used.push_back(keys[j]);
    }

    res = min(res, get(people, used));
  }

  cout << res;

}
