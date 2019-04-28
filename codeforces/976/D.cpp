#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))

typedef long long Long;

const int N = 303;

struct Edge {
  int u, v;
  Edge(int u, int v) :
    u(u), v(v) {
  }
};

vector<Edge> edges;

vector<Edge> construct(vector<int>& deg_set) {
  vector<Edge> res;

  int curr_node = 1;
  for (int first = 0, last = deg_set.size() - 1; first <= last;
    ++first, --last) {
    for (int i = 0; i < deg_set[first]; ++i) {
      for (int j = i + 1 ; j <= deg_set[last] ; ++j) {
        res.emplace_back(curr_node + i , curr_node + j);
      }
    }
    curr_node += deg_set[first];
    for (int i = first + 1 ; i < last ; ++i) {
      deg_set[i] -= deg_set[first];
    }
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

  int n;
  cin >> n;

  vector <int> deg_set(n);
  for (int& x : deg_set) {
    cin >> x;
  }

  auto res = construct(deg_set);
  cout << res.size() << endl;
  for (auto& edge : res) {
    cout << edge.u << " " << edge.v << endl;
  }

}
