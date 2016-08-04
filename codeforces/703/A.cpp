#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int c = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    c += (a > b) - (a < b);
  }
  if (c > 0) cout << "Mishka" ;
  if (c < 0) cout << "Chris" ;
  if (c == 0) cout << "Friendship is magic!^^" ;
}
