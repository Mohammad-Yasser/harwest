#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

int ask(const vector<int>& v) {
  cout << "? " << v.size();
  for (int x : v) {
    cout << " " << x;
  }
  cout << endl;
  int res;
  cin >> res;
  return res;
}

int mx;

vector<int> generateVector(int l, int r) {
  vector<int> res;
  for (int i = l; i <= r; ++i) {
    res.emplace_back(i);
  }
  return res;
}

int getMaxIndex(int l, int r) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  auto left = generateVector(l, mid);
  if (ask(left) == mx) {
    return getMaxIndex(l, mid);
  }
  return getMaxIndex(mid + 1, r);
}

vector<vector<int>> subsets;
int n;
vector<int> getComplement(const vector<int>& subset) {
  vector<int> complement;
  for (int i = 1; i <= n; ++i) {
    if (!binary_search(all(subset), i)) {
      complement.emplace_back(i);
    }
  }
  return complement;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int k;
    cin >> n >> k;
    subsets.resize(k);
    for (auto& subset : subsets) {
      int c;
      cin >> c;
      subset.resize(c);
      cin >> subset;
      sort(all(subset));
    }
    mx = ask(generateVector(1, n));
    int mx_ind = getMaxIndex(1, n);
    vector<int> res;
    for (auto& subset : subsets) {
      if (binary_search(all(subset), mx_ind)) {
        res.emplace_back(ask(getComplement(subset)));
      } else {
        res.emplace_back(mx);
      }
    }
    cout << "! " << res << endl;
    cout << endl;
    string correct;
    cin >> correct;  // :sunglasses:
  }

  return 0;
}