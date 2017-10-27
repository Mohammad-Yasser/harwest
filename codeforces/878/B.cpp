#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2e5 + 5;

typedef vector<pair<int, Long>> VP;
int n, k, m;

VP normalize(const VP& v) {
  VP res;
  int curr = 0;
  while (curr < v.size()) {
    while (!res.empty() && curr < v.size() && v[curr].first == res.back().first) {
      res.back().second += v[curr].second;
      res.back().second %= k;
      if (res.back().second == 0) {
        res.pop_back();
      }
      ++curr;
    }
    if (curr == v.size()) break;
    res.push_back(v[curr]);
    ++curr;
  }

  return res;
}

Long getSz(const VP& v) {
  Long res = 0;
  for (auto& x : v) {
    res += x.second;
  }
  return res;
}

struct Comp {
  VP all;

  void norm() {
    all = normalize(all);
    if (all.size() <= 2 * N) return;
    Long sz = getSz(all);
    VP res;
    for (int i = 0; i < N; ++i) {
      res.push_back(all[i]);
      sz -= all[i].second;
    }
    res.emplace_back(-1, 0);
    int mid_ind = res.size() - 1;
    for (int i = (int) all.size() - N; i < all.size(); ++i) {
      res.push_back(all[i]);
      sz -= all[i].second;
    }
    res[mid_ind].second = sz;
    all = res;
  }

  void print() {
    cout << "All: ";
    for (auto& x : all) {
      cout << "{" << x.first << "," << x.second << "}" << " ";
    }
    cout << endl;
    cout << "Sz: " << getSz(all) << endl;
  }
};

VP base_vp;

VP concat(const VP& a, const VP& b) {
  VP res;

  res.insert(res.end(), a.begin(), a.end());
  res.insert(res.end(), b.begin(), b.end());

  return res;
}

Comp calc(int m) {
  if (m == 0) {
    return Comp();
  }

  if (m == 1) {
    Comp res;
    res.all = base_vp;
    return res;
  }

  Comp tmp = calc(m / 2);

  Comp res;

  res.all = concat(tmp.all, tmp.all);

  if (m & 1) {
    res.all = concat(res.all, base_vp);
  }

  res.norm();

//  cout << m << endl;
//  res.print();

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n >> k >> m;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    base_vp.push_back( { x, 1 });
  }

  base_vp = normalize(base_vp);

  Comp res = calc(m);

  cout << getSz(res.all) << endl;
}
