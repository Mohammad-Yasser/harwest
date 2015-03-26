#include <bits/stdc++.h>

using namespace std;
int cnt[100005];
int main() {

    string s;
    int n, tmp;
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        cnt[--tmp]++;
    }
    for (int i = 1; i < s.size() / 2; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < s.size(); ++i) {
        if (i < s.size() / 2)
            cout << ((cnt[i] % 2) ? s[s.size() - i - 1] : s[i]);
        else
            cout << ((cnt[s.size() - i - 1] % 2) ? s[s.size() - i - 1] : s[i]);
    }
    cout << endl;
}
