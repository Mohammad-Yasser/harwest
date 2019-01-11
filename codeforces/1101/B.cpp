#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int first_opening = -1, last_closing = -1;
  int first_colon = -1, last_colon = -1;

  deque<char> dq;

  string s;
  cin >> s;
  dq.insert(dq.begin(), s.rbegin(), s.rend());
  while (!dq.empty() && dq.back() != '[') {
    dq.pop_back();
  }

  while (!dq.empty() && dq.back() != ':') {
    dq.pop_back();
  }

  while (!dq.empty() && dq.front() != ']') {
    dq.pop_front();
  }

  while (!dq.empty() && dq.front() != ':') {
    dq.pop_front();
  }

  if (dq.size() < 2) {
    cout << -1;
    return 0;
  }

  int res = 4;
  for (char c : dq) {
    res += (c == '|');
  }

  cout << res << endl;

}
