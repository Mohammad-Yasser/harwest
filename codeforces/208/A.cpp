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
	string a;
	bool b = 0 ;
	cin >> a;
	while (a.size()>=3)
	{
		if (a.substr(0, 3) == "WUB") {
			a.erase(0, 3);
			if (b)
				cout << " ";

		} else {
			cout << a[0];
			a.erase(0,1) ;
			b = 1;

		}
	}
	cout <<a ;
	return 0;
}
