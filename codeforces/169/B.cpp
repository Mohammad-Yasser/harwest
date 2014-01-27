#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;
const double eps = 1e-9;

int stoi(string s) {
	stringstream ss;
	int i;
	ss << s;
	ss >> i;
	return i;
}
int btod(int x, int b)

{
	int xd = 0, i = 1;
	while (x) {
		xd += (x % 10) * i;
		i *= b;
		x /= 10;
	}
	return xd;
}

int main() {
	ios_base::sync_with_stdio(0);


	string s;
	cin >> s;
	char c;
	vector<char> q;
	while (cin >> c)
		q.push_back(c);
	sort(q.begin(),q.end()) ;
	vector<char>::iterator it=q.end() ;
	it-- ;
	for (int i = 0; i < s.size(); ++i) {


		if (s[i] < *it) {
			s[i] = *it;
			q.erase(it--);
		}
	}
	cout << s;

	return 0;
}
