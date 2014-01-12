#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a = 0, b = 0;
	vector<int> t;
	t.resize(n);
	for (int i = 0; i < n; cin >> t[i], ++i)
		;
	bool bb = 0;
while ((bool)(t.size()))
{
if (t[0]>t[t.size()-1])
{
	if (bb)
	{a+=t[0];
	t.erase(t.begin());}
	else {	{b+=t[0];
	t.erase(t.begin());}
}

}
else
	if (bb)
		{a+=t[t.size()-1];
		t.erase(t.begin()+t.size()-1);}
		else {	{b+=t[t.size()-1];
		t.erase(t.begin()+t.size()-1);}
}
bb=!bb ;
}
cout << b << " " << a ;

}


//My Name is Ibrahim.
