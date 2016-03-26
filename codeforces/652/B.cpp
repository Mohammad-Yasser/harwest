#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int arr[1003];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; ++i)
		cout << arr[(i >> 1) + (i & 1) * ((n >> 1) + (n & 1))] << ' ';

}
