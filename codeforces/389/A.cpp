#include <bits/stdc++.h>

using namespace std;


int main() {

	int n;
	cin >> n ;
	int a ;
	cin >>a;
	int m=a ;

	for (int i = 1; i < n; cin>>a,m=__gcd(m,a),++i) ;
	cout << n*m;

}
