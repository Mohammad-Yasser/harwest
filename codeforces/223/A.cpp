#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const int N = 100005;
const string kBrackets = "()[]";

string s;
int end_[N];

char Opposite(char c) {
  return kBrackets[kBrackets.find(c) ^ 1];
}

bool IsClosing(char c) {
  return kBrackets.find(c) & 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  cin >> s;
  stack<int> st;
  int n = s.size();

  for (int i = 0; i < n; ++i) {
    if (IsClosing(s[i])) {
      int top = st.empty() ? i : st.top();
      if (Opposite(s[i]) == s[top]) {
        end_[top] = i;
        st.pop();
      } else {
        st = stack<int>();
      }
    } else {
      st.push(i);
    }
  }

  int curr = 0;
  int last = 0;

  int mx = 0;
  int best_ind = 0;
  int best_last = 0;

  while (curr < n) {
    if (IsClosing(s[curr]) || end_[curr] == 0) {
      ++curr;
      continue;
    }
    last = end_[curr];
    while (last < n && !IsClosing(s[last + 1]) && end_[last + 1] != 0) {
      last = end_[last + 1];
    }
    int cnt = count(s.begin() + curr, s.begin() + last + 1, '[');
    if (cnt > mx) {
      mx = cnt;
      best_ind = curr;
      best_last = last;
    }
    curr = last + 1;
  }

  cout << mx << '\n';
  if (mx > 0) {
    for (int i = best_ind; i <= best_last; ++i) {
      cout << s[i];
    }
  }

}
