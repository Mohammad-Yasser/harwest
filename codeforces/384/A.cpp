#include <bits/stdc++.h>
using namespace std;
int main()
{
int n ;
cin >> n ;
cout << n*n/2 + n%2 <<endl;
for (int i=0 ; ++i <=n ;cout <<endl)
{
	for (int ii=0 ; ++ii<=n;)
	cout << (i%2==ii%2 ? 'C' : '.') ;
}
}
