#include <bits/stdc++.h> 
using namespace std;


int main() {

	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

	int n,mn=INT_MAX ;
	long long ans = 0 ;

	cin >> n ;

	while (n--){
		int a,b ;
		cin >> b >> a ;
		mn = min(mn,a) ;
		ans += mn * b ;
	}

	cout << ans ;


}
