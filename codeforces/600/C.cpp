#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int cnt[128];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;

	for (char x : s)
		++cnt[x];

	int first = 'a', last = 'z';

	while (first != last) {
		while (last > first && ((cnt[last] & 1) == 0))
			--last;
		while (first < last && ((cnt[first] & 1) == 0))
			++first;

		++cnt[first];
		--cnt[last];
	}

	string left;
	char odd = 0;
	for (int i = 'a'; i <= 'z'; ++i)
		left += string(cnt[i] / 2, i);

	string right = left ;
	reverse(right.begin(),right.end()) ;

	if (s.size() & 1) left += first;

	cout << left + right ;

}
