#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char Decipher(char c) {
  if (isdigit(c)) return c - '0';
  if (isupper(c)) return 10 + c - 'A';
  if (islower(c)) return 36 + c - 'a';
  if (c == '-') return 62;
  if (c == '_') return 63;
  return 0;
}

int CountZeroes(int x) {
  int res = 0;
  for (int i = 0; i < 6; ++i) {
    if (((x >> i) & 1) == 0) {
      ++res;
    }
  }
  return res;
}

int CountZeroes(const string& s) {
  int res = 0;
  for (char c : s) {
    res += CountZeroes(Decipher(c));
  }
  return res;
}

const int MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  string s;
  cin >> s;
  int cnt = CountZeroes(s);

  int res = 1;

  while (cnt--) {
    res = (3LL * res) % MOD;
  }
  cout << res;

}
