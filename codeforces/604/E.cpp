#include <bits/stdc++.h>

using namespace std;

int n, k;
// k Even :  0 , 1 , 2 , 0 , 1 , 0 , 1
// k Odd : 0 , 1 , 0 , 1 , 2 , 0 , 2 , 0 , 1 , 0 , 1
int g(int n) {
	if (!k) {
		if (n < 3) return n;
		return !(n & 1);
	}
	if (n == 4) return 2 ;
	if (n < 4) return n & 1;
	if (n & 1) return 0;

	return (g(n / 2) == 1) + 1;

}

int main() {

	cin >> n >> k;
	k &= 1;

  int ans = 0 , tmp ;
  while (n--) {
  	cin >> tmp ;
  	ans ^= g(tmp) ;
  }

  cout << (ans ? "Kevin" : "Nicky") ;

}
