#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N = 51;
int p[N], t[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	int limak = 0, tm = 0;
	for (int i = 0; i < n; ++i)
		limak += max(0, p[i] - c * (tm += t[i]));
	tm = 0;
	int rad = 0;
	for (int i = n - 1; i >= 0; --i)
		rad += max(0, p[i] - c * (tm += t[i]));
	if (limak == rad)
		cout << "Tie";
	else if (limak < rad)
		cout << "Radewoosh";
	else
		cout << "Limak";
}
