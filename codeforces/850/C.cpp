#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

map<int, vector<int>> mp;

void add(int x) {
  for (Long i = 2; i * i <= x; ++i) {
    int cnt = 0;
    while (x % i == 0) {
      ++cnt;
      x /= i;
    }
    mp[i].push_back(cnt);
  }
  if (x != 1) {
    mp[x].push_back(1);
  }
}

map<vector<int>, int> grundy;

vector<int> getVM(vector<int> v, int x) {
  for (auto& i : v) {
    if (i >= x) {
      i -= x;
    }
  }
  sort(v.rbegin(), v.rend());
  while (!v.empty() && v.back() == 0)
    v.pop_back();
  return v;
}

int G(vector<int> v) {
  sort(v.rbegin(), v.rend());
  if (v.empty()) return 0;
  if (grundy.count(v)) {
    return grundy[v];
  }

  set<int> st;
  for (int i = 1; i <= v[0]; ++i) {
    int g = G(getVM(v, i));
    st.insert(g);
  }
  int res = 0;
  while (st.count(res)) {
    ++res;
  }
  return grundy[v] = res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  while (n--) {
    int x;
    cin >> x;
    add(x);
  }

  int res = 0;

  for (auto& p : mp) {
    res ^= G(p.second);
  }

  cout << (res != 0 ? "Mojtaba" : "Arpa");

}
