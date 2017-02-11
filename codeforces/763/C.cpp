#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unordered_set<ll> Set;

ll m;

ll Power(ll b, ll p, ll mod) {
  if (p == 0) return 1;
  ll tmp = Power(b, p / 2, mod);
  tmp = 1LL * tmp * tmp % mod;
  if (p & 1) {
    tmp = 1LL * tmp * b % mod;
  }
  return tmp;
}

ll GetD(const Set& arr) {
  auto it = arr.begin();
  ++it;
  ll x = (*it - *arr.begin() + m) % m;

  ll k = arr.size();

  for (auto& it : arr) {
    if (arr.count((it + x) % m)) {
      --k;
    }
  }

  ll d = 1LL * x * Power(k, m - 2, m) % m;

  return d;
}

bool CheckValid(Set arr, ll d, ll& a) {
  ll b = *arr.begin();
  ll curr = b;

  a = b;

  for (int i = 0; i < 2; ++i) {
    while (arr.count(curr)) {
      if (i == 1) {
        a = curr;
      }
      arr.erase(arr.find(curr));
      curr = (curr + d) % m;
    }

    d = (m - d) % m;
    curr = (b + d) % m;
  }

  return arr.empty();
}

void Solve(const Set& arr, ll& a, ll& d) {
  if (arr.size() == 0) {
    a = 0;
    d = 1;
    return;
  }
  if (arr.size() == 1) {
    a = *arr.begin();
    d = 1;
    return;
  }

  d = GetD(arr);

  a = -1;
  if (!CheckValid(arr, d, a)) {
    a = -1;
  }
}

Set GetComplement(const Set& arr, ll m) {
  Set res;
  for (ll i = 0; i < m; ++i) {
    if (arr.count(i)) continue;
    res.insert(i);
  }
  return res;
}

ll GetMod(ll x) {
  return (x % m + m) % m;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
  ll n;
  cin >> m >> n;

  Set arr;

  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    arr.insert(x);
  }
  ll a, d;

  if (2 * n > m) {
    arr = GetComplement(arr, m);
    Solve(arr, a, d);

    if (a != -1) {
      a = GetMod(a - n * d);
    }
  } else {
    Solve(arr, a, d);
  }

  if (a == -1) {
    cout << -1;
  } else {
    cout << a << ' ' << d;
  }

}
