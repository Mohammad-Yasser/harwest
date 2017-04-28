#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e6 + 1;

int k;
string s;

int next_space[N];

bool Can(int width, string&& res = "") {
  int cnt_lines = 1;
  int ind = 0;
  int curr_line_width = 0;

  while (ind < s.size() && cnt_lines <= k) {
    if (s[ind] != ' ' || next_space[ind] - ind + curr_line_width + 1 <= width) {
      res += s[ind];
      ++ind;
      ++curr_line_width;
      continue;
    }
    res += s[ind];
    res += '\n';

    curr_line_width = 0;
    ++ind;
    ++cnt_lines;
  }

  return ind == s.size();
}

void Build() {
  int last_space = s.size() - 1;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == ' ') {
      for (int j = last_space - 1; j >= i; --j) {
        next_space[j] = last_space;
      }
      last_space = i;
    }
  }
}

int GetMinWidth() {
  int last_space = -1;
  int mx = 0;

  for (int i = 0; i <= s.size(); ++i) {
    if (i == s.size() || s[i] == ' ') {
      mx = max(mx, i - last_space - (i == s.size()));
      last_space = i;
    }
  }
  return mx;
}

int Solve() {
  int low = GetMinWidth(), high = 1e6 + 1, mid, ans = -1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (Can(mid)) {
      high = mid - 1;
      ans = mid;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> k;
  cin.ignore();
  getline(cin, s);

  replace(s.begin(), s.end(), '-', ' ');

  Build();

  cout << Solve() << '\n';
}
