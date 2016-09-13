#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int N = 1e4;

bool solve() {
  map<int, int> cnt;

  int n;
  cin >> n;
  while (n--) {
    int tmp;
    cin >> tmp;
    ++cnt[tmp];
  }

  if (cnt.size() < 3) return true;
  if (cnt.size() > 3) return false;
  if (cnt.begin()->first % 2 != cnt.rbegin()->first % 2) return false;
  if (cnt.count((cnt.begin()->first + cnt.rbegin()->first) / 2)) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  if (solve())
    cout << "Yes";
  else
    cout << "No";
}
