#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000006;

int n;
ll res[N];
string s;

void Solve(bool flipped) {
  char U = 'U', D = 'D';
  if (flipped) swap(U, D);

  vector<ll> u, d;
  u.push_back(0);
  d.push_back(0);

  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == U) continue;
    d.push_back(i + d.back());
  }

  for (int i = 0; i < n; ++i) {
    ll &ans = res[i];

    if (s[i] == D) {
      d.pop_back();
      continue;
    }

    ll mn = min(u.size(), d.size()) - 1;
    ll left = mn, right = mn + (mn < d.size() - 1);

    ans += 2 * (left * i - (u.back() - u[u.size() - 1 - left]));
    ans += 2 * ((d.back() - d[d.size() - 1 - right]) - right * i);

    if (left < right) {
      ans += i + 1;
    } else {
      ans += n - i;
    }

    u.push_back(i + u.back());
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  cin >> n >> s;

  Solve(false);
  reverse(s.begin(), s.end());
  reverse(res, res + n);
  Solve(true);
  reverse(res, res + n);

  for (int i = 0; i < n; ++i) {
    cout << res[i] << ' ';
  }

}
