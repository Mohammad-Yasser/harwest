#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	char b[n][n];
	bool q[n][n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; q[i][j] = 0, cin >> b[i][j++])
			;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n; ++j)

			if (b[i][j] == '#' &&  b[i][j + 1] == '#' && b[i][j + 2] == '#'
					&& b[i - 1][j + 1] == '#' && b[i + 1][j + 1] == '#')
				{q[i][j] = q[i][j + 1] = q[i][j + 2] = q[i - 1][j + 1] =
						q[i + 1][j + 1] = 1;
				b[i][j] = b[i][j + 1] = b[i][j + 2] = b[i - 1][j + 1] =
										b[i + 1][j + 1] = '0';}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (q[i][j] == 0 && b[i][j] == '#') {
				cout << "NO";
				return 0;
			}
	;
	cout << "YES" ;
	cerr << q[2][2] ;

}
