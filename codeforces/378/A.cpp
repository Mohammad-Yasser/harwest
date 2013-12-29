#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int a ,b ;
	cin >> a >> b ;
	int w=0,d=0,l=0 ;
	for (int i=1 ; i <7 ; i++)
	{
		w+=abs(a-i) > abs(b-i) ;
		d+=abs(a-i) == abs(b-i) ;
		l+=abs(a-i) < abs(b-i) ;
	}
	cout << l << " " << d << " " << w ;
}
