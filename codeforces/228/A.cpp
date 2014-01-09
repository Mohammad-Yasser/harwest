#include <bits/stdc++.h>


using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

int main() 
{ 
	
	int arr[4] ;
	int y=0 ;
	for (int i=0 ; i<4 ;++i)
	{
		cin >> arr[i] ;
		y+= (bool)count(arr,arr+i,arr[i]) ;
	}
	cout << y ;

























































	return 0;
}
