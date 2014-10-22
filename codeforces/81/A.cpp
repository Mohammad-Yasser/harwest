#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    bool arr[s.size()];
    fill(arr, arr + s.size(), 1);
    vector<int> tmp;
    for (int i = 0; i < s.size(); ++i) {
        if (tmp.size() && s[i] == s[tmp[tmp.size() - 1]]) {
            arr[i] = arr[tmp[tmp.size() - 1]] = 0;
            tmp.erase(tmp.end() - 1);

        } else
            tmp.push_back(i);
    }
    for (int i = 0; i < s.size(); ++i)
        if (arr[i])
            cout << s[i];
}
