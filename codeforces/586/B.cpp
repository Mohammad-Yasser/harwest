#include <bits/stdc++.h> 
using namespace std;

int main() {

	int n;
	cin >> n;
	int a[2][n];

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n - 1; ++j)
			cin >> a[j][i];

	int b[n];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	int mn = INT_MAX;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j) {
				int tmp = b[i] + b[j];
				for (int ind = 0; ind < i; ++ind)
					tmp += a[ind][0];

				for (int ind = 0; ind < j; ++ind)
					tmp += a[ind][0];

				for (int ind = i; ind < n - 1; ++ind)
					tmp += a[ind][1];

				for (int ind = j; ind < n - 1; ++ind)
					tmp += a[ind][1];


				mn = min(mn,tmp) ;
			}

	cout << mn ;

}
