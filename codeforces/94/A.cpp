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
	string s ;
	cin >> s ;
	string arr[10] ;
	for (int i =0 ; i<10 ; cin >> arr[i] , i++) ;
	for (int i=0 ; i < 80 ; i+=10)
	{
		for (int q=0 ; q < 10 ; q++)
			if (s.substr(i,10)==arr[q])
				{cout << q ;break;}
	}
	return 0;
}
