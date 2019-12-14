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
typedef long long Long;

// gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5;
const int K = 6;

string sig = "onetw";

int getC(char c) {
  int res = sig.find(c);
  if (res == string::npos) res = sig.size();
  return res;
}

int memo[N][K][K];
int vis[N][K][K];
int vid;
string s;

string getS(int prev1, int prev2) {
  string res;
  res += (prev2 == sig.size() ? '!' : sig[prev2]);
  res += (prev1 == sig.size() ? '!' : sig[prev1]);
  return res;
}

bool candidate(int prev1, int prev2) {
  string tmp = getS(prev1, prev2);
  return (tmp == "on" || tmp == "tw" || tmp[1] == 'o' || tmp[1] == 't');
}

int solve(int ind, int prev1, int prev2) {
  if (ind == s.size()) return 0;
  if (!candidate(prev1, prev2)) {
    prev1 = prev2 = sig.size();
  }
  int& res = memo[ind][prev1][prev2];
  if (vis[ind][prev1][prev2] == vid) return res;
  vis[ind][prev1][prev2] = vid;

  string curr = getS(prev1, prev2) + s[ind];
  if (curr == "one" || curr == "two") {
    res = 1 + solve(ind + 1, prev1, prev2);
  } else {
    res = 1 + solve(ind + 1, prev1, prev2);
    res = min(res, solve(ind + 1, getC(s[ind]), prev1));
  }

//  cout << ind << " " << prev1 << " " << prev2 << " " << getS(prev1, prev2)
//    << " " << res << endl;
  return res;
}

void buildPath(int ind, int prev1, int prev2, vector<int>& res) {
  if (ind == s.size()) return;
  if (!candidate(prev1, prev2)) {
    prev1 = prev2 = sig.size();
  }

  string curr = getS(prev1, prev2) + s[ind];
  if (curr == "one" || curr == "two") {
    res.push_back(ind);
    buildPath(ind + 1, prev1, prev2, res);
  } else {
    if (1 + solve(ind + 1, prev1, prev2)
      < solve(ind + 1, getC(s[ind]), prev1)) {
      res.push_back(ind);
      buildPath(ind + 1, prev1, prev2, res);
    } else {
      buildPath(ind + 1, getC(s[ind]), prev1, res);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    ++vid;
    cin >> s;

    vector<int> res;
    buildPath(0, K - 1, K - 1, res);
    cout << res.size() << endl;
    for (int x : res) {
      cout << x + 1 << " ";
    }
    cout << endl;
  }
}