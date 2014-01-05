#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long int ull;

int main() {
	int n ;
	ull s=0 ;
	cin >> n ;
	int y ;
	map<int,ull> a ;
	for (int i=0 ; i <n ; cin >> y ,a[y]++, i++) ;

	for (int i = 1; i < 11; ++i) {

		s+=a[i]*a[-1*i] ;

	}

	s+=(a[0])*(a[0]-1)/2 ;



	cout << s ;
	return 0;
}
