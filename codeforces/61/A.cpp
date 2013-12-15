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
	string a,b ;
	cin >> a >> b ;
	for (int i =0 ; i <a.size() ; i++)
		if (a[i]==b[i]) cout << 0 ;
		else cout << 1 ;
	return 0;
}
