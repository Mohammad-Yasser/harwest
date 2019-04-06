#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e3 + 5;

int n, h;
int a[N];

Long getReq(const vector<int>& v) {
  Long res = 0;
  for (int i = 1; i < v.size(); i += 2) {
    res += v[i];
  }
  return res;
}

bool valid(int k) {
  vector<int> v(a, a + k);
  sort(v.begin(), v.end());
  Long req;

  if (v.size() % 2 == 0) {
    req = getReq(v);
  } else {
    auto v1 = v;
    v1.pop_back();
    req = getReq(v1) + v.back();
    v1 = v;
    v1.erase(v1.begin());
    req = min(req , getReq(v1) + v[0]);
  }

  return req <= h;
}

int bs() {
  int low = 1, high = n, ans = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (valid(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> h;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }


  cout << bs() << endl;

}

