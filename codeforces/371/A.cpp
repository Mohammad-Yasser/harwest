#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
	int n, k, i, j, ret = 0, a1, a2;
	int arr[105];
	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < k; i++) {
		a1 = a2 = 0;
		for (j = i; j < n; j += k)
			arr[j] == 1 ? a1++ : a2++;
		ret += min(a1, a2);
	}
	cout << ret << endl;
	return 0;
}
