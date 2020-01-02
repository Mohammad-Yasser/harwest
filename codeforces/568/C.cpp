#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
#define all(x) x.begin(),x.end()
typedef long long Long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// https://github.com/kmyk/competitive-programming-library
/**
 * @param g is an adjacent list of a digraph
 * @note $O(V + E)$
 * @see https://en.wikipedia.org/wiki/Transpose_graph
 */
vector<vector<int>> make_transpose_graph(const vector<vector<int>>& g) {
  int n = g.size();
  vector<vector<int>> h(n);
  for (int i = 0; i < n; ++i) {
    for (int j : g[i]) {
      h[j].push_back(i);
    }
  }
  return h;
}

/**
 * @brief strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解
 * @return the pair (the number k of components, the function from vertices of g to components)
 * @param g is an adjacent list of a digraph
 * @param g_rev is the transpose graph of g
 * @note $O(V + E)$
 */
pair<int, vector<int>> decompose_to_strongly_connected_components(
  const vector<vector<int>>& g, const vector<vector<int>>& g_rev) {
  int n = g.size();
  vector<int> acc(n);
  {
    vector<bool> used(n);
    function<void(int)> dfs = [&](int i) {
      used[i] = true;
      for (int j : g[i]) if (not used[j]) dfs(j);
      acc.push_back(i);
    };
    for (int i = 0; i < n; ++i)
      if (not used[i]) dfs(i);
    reverse(all(acc));
  }
  int size = 0;
  vector<int> component_of(n);
  {
    vector<bool> used(n);
    function<void(int)> rdfs = [&](int i) {
      used[i] = true;
      component_of[i] = size;
      for (int j : g_rev[i]) if (not used[j]) rdfs(j);
    };
    for (int i : acc)
      if (not used[i]) {
        rdfs(i);
        ++size;
      }
  }
  return {size, move(component_of)};
}

pair<int, vector<int>> decompose_to_strongly_connected_components(
  const vector<vector<int>>& g) {
  return decompose_to_strongly_connected_components(g, make_transpose_graph(g));
}

auto node_ind = [](int x, int n) {
//  cout << x << " " << n << endl;
  assert (x != 0 and abs(x) <= n); return ((abs(x)-1) << 1) | (x > 0);};
auto opposite = [](int x) {return x ^ 1;};

vector<bool> twosat(int n, const vector<pair<int, int>>& cnf,
  bool convert_to_node_ids = false) {
  // make digraph
  vector<vector<int>> g(2 * n);

  for (auto it : cnf) {
    int x, y;
    tie(x, y) = it; // x or y
    if (convert_to_node_ids) {
      g[node_ind(-x, n)].push_back(node_ind(y, n)); // not x implies y
      g[node_ind(-y, n)].push_back(node_ind(x, n)); // not y implies x
    } else {
      g[opposite(x)].emplace_back(y); // not x implies y
      g[opposite(y)].emplace_back(x); // not y implies x
    }
  }
  // do SCC
  vector<int> component = decompose_to_strongly_connected_components(g).second;
  vector<bool> valuation(n);
  for (int x = 1; x <= n; ++x) {
    if (component[node_ind(x, n)] == component[node_ind(-x, n)]) { // x iff not x
      return vector<bool>(); // unsat
    }
    valuation[x - 1] = component[node_ind(x, n)] > component[node_ind(-x, n)]; // use components which indices are large
  }
  return valuation;
}

const int A = 26;
vector<bool> is_vowel;
int n, m;
char largest_vowel, largest_consonant;
char smallest_vowel, smallest_consontant;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string L;
  cin >> L;
  is_vowel.resize(L.size());
  for (int i = 0; i < L.size(); ++i) {
    is_vowel[i] = (L[i] == 'V');
    if (is_vowel[i]) {
      largest_vowel = (i + 'a');
      if (smallest_vowel == 0) {
        smallest_vowel = largest_vowel;
      }
    } else {
      largest_consonant = (i + 'a');
      if (smallest_consontant == 0) {
        smallest_consontant = largest_consonant;
      }
    }
  }
  cin >> n >> m;
  vector<pair<int, int>> cnf(m);

  for (auto& clause : cnf) {
    int x, y;
    char a, b;
    cin >> x >> a >> y >> b;
    a = (a == 'V'), b = (b == 'V');
    int y_node = node_ind((b ? y : -y), n);
    int x_not_node = node_ind(-(a ? x : -x), n);
    if ((b && largest_vowel == 0) || (!b && largest_consonant == 0)) {
      clause = make_pair(x_not_node, x_not_node);
    } else if ((!a && largest_vowel == 0) || (a && largest_consonant == 0)) {
      clause = make_pair(y_node, y_node);
    } else {
      clause = make_pair(x_not_node, y_node);
    }
  }

  string s;
  cin >> s;

  int first_change = n;
  for (; first_change >= 0; --first_change) {
    auto nxt_cnf = cnf;
    if (first_change != n) {
      if (s[first_change] == max(largest_consonant, largest_vowel)) continue;
      if (min(largest_consonant, largest_vowel) < s[first_change] + 1) {
        int x = first_change + 1;
        int node = node_ind(is_vowel[s[first_change] - 'a' + 1] ? x : -x, n);
        nxt_cnf.emplace_back(node, node);
      }
    }
    for (int i = 0; i < first_change; ++i) {
      int x = i + 1;
      int node = node_ind(is_vowel[s[i] - 'a'] ? x : -x, n);
      nxt_cnf.emplace_back(node, node);
    }
    if (!twosat(n, nxt_cnf).empty()) {
      cnf = nxt_cnf;
      break;
    }
  }

  if (first_change < 0) {
    cout << -1 << endl;
    return 0;
  }

  if (first_change == n) {
    cout << s << endl;
    return 0;
  }

  ++s[first_change];
  int x = first_change + 1;
  int node = node_ind(is_vowel[s[first_change] - 'a'] ? x : -x, n);
  cnf.emplace_back(node, node);
  if (twosat(n, cnf).empty()) {
    cnf.pop_back();
    cnf.emplace_back(opposite(node), opposite(node));
    bool b = is_vowel[s[first_change] - 'a'];
    while (is_vowel[s[first_change] - 'a'] == b) {
      ++s[first_change];
    }
  }

  for (int i = first_change + 1; i < n; ++i) {
    int x = i + 1;
    s[i] = 'a';
    int node = node_ind(is_vowel[0] ? x : -x, n);
    cnf.emplace_back(node, node);
    if (twosat(n, cnf).empty()) {
      cnf.pop_back();
      cnf.emplace_back(opposite(node), opposite(node));
      s[i] = max(smallest_consontant, smallest_vowel);
    }
  }

  auto val = twosat(n, cnf);
  for (int i = 0; i < s.size(); ++i) {
    if (is_vowel[s[i] - 'a'] != val[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << s << endl;
}
