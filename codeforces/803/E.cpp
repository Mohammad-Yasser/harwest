#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e3 + 3;

int memo[N][2 * N];
string s;
int n, k;

string outcomes = "WDL";
int scores[] = { 1, 0, -1 };

bool Can(int ind, int diff) {
  if (ind == n) return abs(diff) == k;
  if (abs(diff) == k) return false;

  int& res = memo[ind][diff + N];
  if (res != -1) return res;

  if (s[ind] != '?') {
    return res = Can(ind + 1, diff + scores[outcomes.find(s[ind])]);
  }

  for (int i = 0; i < 3; ++i) {
    if (Can(ind + 1, diff + scores[i])) {
      return res = true;
    }
  }

  return res = false;
}

void Build(int ind, int diff) {
  if (ind == n) return;

  if (s[ind] != '?') {
    Build(ind + 1, diff + scores[outcomes.find(s[ind])]);
    return;
  }

  for (int i = 0; i < 3; ++i) {
    if (Can(ind + 1, diff + scores[i])) {
      s[ind] = outcomes[i];
      Build(ind + 1, diff + scores[i]);
      return;
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n >> k >> s;

  memset(memo, -1, sizeof memo);

  if (!Can(0, 0)) {
    cout << "NO";
    return 0;
  }

  Build(0 , 0);

  cout << s << endl;
}
