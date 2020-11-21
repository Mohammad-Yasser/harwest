#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
typedef long long Long;
typedef double Double;

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
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 2e5 + 5;
int parent[N];
int score[N];
vector<int> leaves_after[N];
bool seen[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<int> v(n - 1);
  cin >> v;
  for (int i = 0; i + 1 < n; ++i) {
    if (seen[v[i]]) continue;
    seen[v[i]] = true;
    leaves_after[i].emplace_back(v[i]);
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      curr_leaves;
  for (int i = 1; i <= n; ++i) {
    if (!seen[i]) {
      curr_leaves.emplace(i, i);
    }
    score[i] = i;
  }
  for (int i = n - 2; i >= 0; --i) {
    auto curr_leaf = curr_leaves.top();
    curr_leaves.pop();
    parent[curr_leaf.second] = v[i];
    score[v[i]] = max(score[v[i]], curr_leaf.first);
    for (int x : leaves_after[i]) {
      curr_leaves.emplace(score[x], x);
    }
  }

  cout << curr_leaves.top().second << endl;
  for (int i = 1; i <= n; ++i) {
    if (parent[i] != 0) {
      cout << parent[i] << " " << i << endl;
    }
  }

  return 0;
}