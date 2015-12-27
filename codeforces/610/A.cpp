#include <iostream>
using namespace std;
int main() {

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	if (n & 1) {
		cout << 0;
		return 0;
	}
	n >>= 1;
	cout << n / 2 - !(n & 1);

}
