#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;
    for (int i = 0; i < s.size() && n; ++i) {
        int ind = max_element(s.begin() + i,
                s.begin() + min((int) s.size(), i + n + 1)) - s.begin();
        if (s[i] < s[ind])
            for (; ind > i; swap(s[ind], s[ind - 1]), --ind, --n)
                ;

    }
    cout << s;

}
