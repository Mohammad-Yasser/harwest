#include<bits/stdc++.h>
using namespace std;

int memo[100005][2][2][2];
bool arr[100005];
int n;

int DP(int ind, bool last, bool inFlip, bool canFlip) {
	int &ret = memo[ind][last][inFlip][canFlip];
	if (ret != -1) return ret;
	if (ind == n) return ret = 1;


	ret = !!ind * DP(ind + 1, last, inFlip, canFlip);

	ret = max(ret, (!inFlip) * (DP(ind + 1, arr[ind], 0, canFlip) + (arr[ind] != last && ind)));

	ret = max(ret,
	  (inFlip or canFlip) * (DP(ind + 1, !arr[ind], 1, 0) + (arr[ind] == last && ind)));



	ret = max(ret, DP(ind + 1, arr[ind], 0, 0) + (arr[ind] != last && ind));

//	cout << ind << ' ' << last << ' ' << inFlip << ' ' << canFlip << ' ' << ret << endl;

	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(memo, -1, sizeof memo);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		arr[i] = (c == '1');
	}

	cout <<  DP(0, 0, 0, 1);

	return 0;
}
