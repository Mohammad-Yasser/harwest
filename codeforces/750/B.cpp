#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void GetDir(const string& d, int& dx) {
  dx = 0;
  if (d == "North") dx = -1;
  if (d == "South") dx = 1;
}

const int kEquator = 40000;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  int x = 0;

  while (n--) {
    int t;
    string d;
    cin >> t >> d;
    int dx;
    GetDir(d, dx);

    while (t--) {
      if (x == 0 && d != "South") {
        cout << "NO";
        return 0;
      }
      if (x == kEquator / 2 && d != "North") {
        cout << "NO";
        return 0;
      }
      x += dx;
    }
  }

  if (x == 0) {
    cout << "YES";
    return 0;
  }
  cout << "NO";

}
