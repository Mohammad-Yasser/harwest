#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int arr[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  string s;
  cin >> s;
  int cnt_0 = count(s.begin(), s.end(), '0');
  int cnt_1 = count(s.begin(), s.end(), '1');
  int cnt_q = count(s.begin(), s.end(), '?');

  int total_turns = s.size() - 2;
  int masha_turns = (total_turns + 1) / 2;

  if (cnt_1 <= masha_turns) {
    cout << "00\n";
  }

  if (cnt_1 - masha_turns < 2 && cnt_1 + cnt_q - masha_turns >= 1) {
    int cnt_q_1 = 1 - (cnt_1 - masha_turns);
    if (s.back() == '1' || (s.back() == '?' && cnt_q_1 > 0)) {
      cout << "01\n";
    }
    if (s.back() == '0' || (s.back() == '?' && cnt_q_1 < cnt_q)) {
      cout << "10\n";
    }
  }

  if (cnt_1 + cnt_q - masha_turns >= 2) {
    cout << "11\n";
  }

}
