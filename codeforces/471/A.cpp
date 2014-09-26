#include <bits/stdc++.h>
using namespace std;

int main() {

	int arr[6];
	for (int i = 0; i < 6; ++i)
		cin >> arr[i];
	sort(arr, arr + 6);
	for (int i = 0; i < 3; ++i) {
		bool b = 1;
		for (int j = i + 1; j < i + 4; ++j)
			b &= arr[i] == arr[j];
		if (b) {
			int tmp1 = (i ? arr[0] : arr[4]), tmp2 = (i == 2 ? arr[1] : arr[5]);
			if (tmp1 - tmp2)
				cout << "Bear";
			else
				cout << "Elephant";
			return 0;
		}
	}
	cout << "Alien";

}
