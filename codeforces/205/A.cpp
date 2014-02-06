#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int mn=2e9, n,x,mni ;
	bool b = 1;
	cin >> n;
	for (int i=1 ; i<=n ; ++i)
	{
		cin >> x ;
		if (x<mn)
		{mn=x;mni=i;b=1;}
		else if (x==mn) b=0 ;


	}
	b ? cout << mni :cout << "Still Rozdil" ;
	return 0;
}
