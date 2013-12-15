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
typedef unsigned long long ull;

int main() {
	int n ; cin >> n ;
	if (n%2!=0) cout << -1 ;
	else
		for (int i=2 ; i <=n ; i+=2)
		{
			cout << i << " " << i-1  << " ";
		}
	return 0;
}
