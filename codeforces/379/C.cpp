#include <bits/stdc++.h>
using namespace std;

bool srt(pair<int, int> i, pair<int, int> j) {
	return i.second < j.second;
}
bool srt2(pair<int, int> i, pair<int, int> j) {
	return i.first < j.first;
}

int main() {
	vector<pair<int, int> > inp;
	int n;
	cin >> n;
	for (int i = 0; cin >> n; ++i)
		inp.push_back(make_pair(i, n));
	sort(inp.begin(), inp.end(),srt);
	for (int i = 1; i < inp.size();
			inp[i].second = max(inp[i - 1].second + 1, inp[i].second), ++i)
		;
	sort(inp.begin(), inp.end(),srt2);
	for (int i=0;i<inp.size();cout<<inp[i].second<<' ',++i) ;

}
