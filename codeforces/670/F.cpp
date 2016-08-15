#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main() {
  string a, b;
  cin >> a >> b;
  for (char x : a) ++cnt[x - '0'];

  int k = 1, k_l = 1, nxt_pw10 = 10;
  while (k + k_l < a.size()) {
    if (++k == nxt_pw10) {
      nxt_pw10 *= 10;
      ++k_l;
    }
  }

  while (k) {
    --cnt[k % 10];
    k /= 10;
  }

  for (char x : b) --cnt[x - '0'];

  string ans = string(1e6, '9');
  if (b[0] != '0') {
    ans = b;
    for (int i = 0; i < 10; ++i) ans += string(cnt[i], i + '0');
  }

  string left, mid, right;

  if (cnt[0]) {
    for (int i = 1; i < 10; ++i)
      if (cnt[i]) {
        left += (i + '0');
        --cnt[i];
        break;
      }
  }

  for (int i = 0; i < 10; ++i) {
    if (i < b[0] - '0')
      left += string(cnt[i], i + '0');
    else if (i == b[0] - '0')
      mid += string(cnt[i], i + '0');
    else
      right += string(cnt[i], i + '0');
  }

  if (left + mid + b + right == "0") {
    cout << "0";
    return 0;
  }

  if (left[0] > '0')
    ans = min({ans, left + b + mid + right, left + mid + b + right});
  else if (b[0] == '0' && left[0] <= '0') {
    left = right.substr(0, 1) + left;
    right.erase(right.begin());
    ans = min(ans, left + mid + b + right);
  }
  cout << ans;
  return 0;
}
