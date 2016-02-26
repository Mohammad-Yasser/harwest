#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

struct Node {
	int ind;
	Node() {
		ind = -1;
	}
	unordered_map<char, Node*> mp;
};

const int N = 10004;
char memo[N];

string s;
Node *root = new Node;
int n;
int res[N];
char dp(short ind) {
	if (ind == n) return 1;
	char &ret = memo[ind];
	if (ret != -1) return ret;
	ret = 0;
	Node *curr = root;
	auto it = root->mp.begin();
	short tmp = ind;

	while (it = curr->mp.find(s[tmp]), it != curr->mp.end()) {
		curr = it->second;
		if (curr->ind != -1 && dp(tmp + 1)) {
			ret = 1;
			res[ind] = curr->ind;
			break;
		}
		++tmp;
	}
	return ret;
}

void add(string s, int ind) {
	Node* curr = root;
	for (char x : s) {
		if (!curr->mp.count(x)) curr->mp[x] = new Node;
		curr = curr->mp[x];
	}

	curr->ind = ind;
}

string arr[100005];


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(memo, -1, sizeof memo);

	cin >> n >> s;
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		string tmp = arr[i];
		reverse(tmp.begin(), tmp.end());
		for (auto &x : tmp)
			x = tolower(x);
		add(tmp, i);
	}

	dp(0);
	int ind = 0;
	while (ind < n) {
		cout << arr[res[ind]] << ' ';
		ind += arr[res[ind]].size();
	}
}
