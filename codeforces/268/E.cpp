#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}

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

struct Song {
  Double l, p;

  bool operator<(const Song& other) const {
    return (1 - p) * other.p * other.l < (1 - other.p) * p * l;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<Song> songs(n);
  for (auto& song : songs) {
    cin >> song.l >> song.p;
    song.p /= 100;
  }

  Double res = 0;
  sort(all(songs));
  Double sum_like_lengths = 0;
  for (auto& song : songs) {
    res += song.l;
    res += (1 - song.p) * sum_like_lengths;
    sum_like_lengths += song.l * song.p;
  }
  cout << fixed << setprecision(10) << res << endl;

  return 0;
}