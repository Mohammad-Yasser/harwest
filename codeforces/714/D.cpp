#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int n;

int upper_y[2];
int upper_x[2];
int lower_y[2];
int lower_x[2];

void Out(int x1, int y1, int x2, int y2, string pr = "? ", bool flush = true) {
	cout << pr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
	if (flush)
	  cout << endl;
}

bool Valid(int x1, int y1, int x2, int y2) {
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);

	int tmp;

	Out(x1, y1, x2, y2);
	cin >> tmp;
	if (tmp != 1) return false;

	if (x1 < x2) {
		Out(x1 + 1, y1, x2, y2);
		cin >> tmp;
		if (tmp) return false;

		Out(x1, y1, x2 - 1, y2);
		cin >> tmp;
		if (tmp) return false;
	}

	if (y1 < y2) {
		Out(x1, y1 + 1, x2, y2);
		cin >> tmp;
		if (tmp) return false;

		Out(x1, y1, x2, y2 - 1);
		cin >> tmp;
		if (tmp) return false;
	}

	return true;

}

void solve1(bool b) {
	int low = 1, high = n, ans, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		Out(1, 1, n, mid);
		int tmp;
		cin >> tmp;
		if (tmp > b)
			ans = mid, high = mid - 1;
		else
			low = mid + 1;
	}
	upper_y[b] = ans;
//	cout << "Upper Y " << ans << endl;
}

void solve2(bool b) {
	int low = 1, high = n, ans, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		Out(1, 1, mid, n);
		int tmp;
		cin >> tmp;
		if (tmp > b)
			ans = mid, high = mid - 1;
		else
			low = mid + 1;
	}
	upper_x[b] = ans;
//	cout << "Upper X " << ans << endl;
}
void solve3(bool b) {
	int low = 1, high = n, ans, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		Out(1, mid, n, n);
		int tmp;
		cin >> tmp;
		if (tmp < 2 - b)
			high = mid - 1;
		else
			ans = mid, low = mid + 1;
	}
	lower_y[b] = ans;
//	cout << "Lower Y " << ans << endl;
}
void solve4(bool b) {
	int low = 1, high = n, ans, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		Out(mid, 1, n, n);
		int tmp;
		cin >> tmp;
		if (tmp < 2 - b)
			high = mid - 1;
		else
			ans = mid, low = mid + 1;
	}
	lower_x[b] = ans;
//	cout << "Lower X " << ans << endl;
}
int main() {
	//  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	solve1(false), solve1(true);
	solve2(false), solve2(true);
	solve3(false), solve3(true);
	solve4(false), solve4(true);

	for (int x1 = 0; x1 < 2; ++x1)
		for (int x2 = 0; x2 < 2; ++x2)
			for (int y1 = 0; y1 < 2; ++y1)
				for (int y2 = 0; y2 < 2; ++y2) {
					int tmp;
					for (int i = 0; i < 2; ++i) {
						if (!Valid(lower_x[x1 ^ i], lower_y[y1 ^ i], upper_x[x2 ^ i], upper_y[y2 ^ i]))
						  goto nxt;
					}

					Out(lower_x[x1], lower_y[y1], upper_x[x2], upper_y[y2], "! ", false);
					Out(lower_x[!x1], lower_y[!y1], upper_x[!x2], upper_y[!y2], " ");
					return 0;
					nxt: ;
				}
}
