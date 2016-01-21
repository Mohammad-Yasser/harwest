#include <bits/stdc++.h>
using namespace std;



int main() {


		int x1 , x2 , y1 , y2 ;
		cin >> x1 >> y1 >> x2 >> y2 ;
		x1 = abs(x1 - x2) , y1 = abs(y1 - y2) ;
		cout << max(x1 , y1) ;


	return 0;
}
