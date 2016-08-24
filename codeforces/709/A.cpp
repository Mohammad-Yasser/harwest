#include <bits/stdc++.h>
using namespace std ;

int main() {
  int n , b , d;
  cin >> n >> b >> d;

  long long curr = 0 ;
  int ans = 0 ;

  while (n--) {
    int tmp ;
    cin >> tmp ;
    if (tmp > b) continue ;
    curr += tmp ;
    if (curr > d) {
      curr = 0 ;
      ++ans ;
    }
  }

  cout << ans ;

}

