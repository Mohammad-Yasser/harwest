#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1003;

unordered_map<int, int> cnt;
int arr[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		++cnt[arr[i]];
	}
	int mx = 0;

	mx = max(mx, cnt[0]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j && (arr[i] or arr[j])) {
				int a = arr[i], b = arr[j];
				vector<int> vec = { a, b };
				--cnt[a], --cnt[b];

				int len = 2;
				while (cnt[a + b]) {
					--cnt[a + b];
					vec.push_back(a+b) ;
					a += b;
					swap(a, b);
					++len;
				}
				for (int x : vec)
					++cnt[x] ;

				mx = max(mx, len);
			}

	cout << mx << '\n';

}
