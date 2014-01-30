#include <bits/stdc++.h>

using namespace std;


int main() {
	int a1,a2,b1,b2 ;
	char c ;
	cin >> a1 >> c>>b1 >> a2 >> c >> b2 ;
	int y1,y2 ;
	y2=b1-b2 ;
	cerr << b1 << " " << b2 ;
	if (y2<0) {y2+=60;a1--;}
	y1=a1-a2 ;
	if (y1<0) y1+=24 ;
	if (y1<10) cout << 0 << y1 ;
	else cout << y1 ;
	cout << ':' ;
	if (y2<10) cout << 0 << y2 ;
	else cout << y2 ;
	return 0;
}
