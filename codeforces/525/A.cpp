#include <bits/stdc++.h>

using namespace std;
int cnt[202], ans;
int main() {
    string s;
    cin >> s >> s;
    for (int i = 0; i < s.size(); ++i)
        if (i % 2)
            s[i] = tolower(s[i]),
              cnt[s[i]] ? --cnt[s[i]] : ++ans;
        else
            cnt[s[i]]++;
    cout << ans;
}
