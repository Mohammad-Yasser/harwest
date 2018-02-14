#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

struct Elem {
  int x, y;
  bool operator <(const Elem& other) const {
    return 1LL * x * other.y > 1LL * y * other.x;
  }
};

Long cnt(const string& s) {
  int x = 0;
  Long res = 0;
  for (char c : s) {
    if (c == 's') {
      ++x;
    } else {
      res += x;
    }
  }
  return res;
}

int main() {

  int n;
  cin >> n;

  vector<Elem> v(n);

  Long res = 0;
  for (auto& x : v) {
    string s;
    cin >> s;

    x.x = count(s.begin(), s.end(), 's');
    x.y = count(s.begin(), s.end(), 'h');
    res += cnt(s);
  }

  sort(v.begin(), v.end());

  string all;
  for (auto& elem : v) {
    all += string(elem.y, 'h');
    all += string(elem.x, 's');
  }

  res += cnt(all);

  cout << res;

}
