#include <bits/stdc++.h> 
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;

int arr[51];

inline bool valid(int i, int j) {
	return arr[i] != arr[j] && abs(arr[i] - arr[j]) < 3;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (valid(i, j))
			  for (int k = j + 1; k < n; ++k)
				  if (valid(i, k) && valid(j, k)) {
					  cout << "YES";
					  return 0;
				  }

	cout << "NO";

}
