#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int x, y;
    cin >> x >> y;
    string m[x];
    int i = 0;
    set<int> pos;
    for (; i < x;
            cin >> m[i], pos.insert(m[i].find('S') - m[i].find('G')),
                    m[i].find('G') > m[i].find('S') ? x = 0 : ++i)
        ;
    if (!x) {
        cout << -1;
        return 0;
    }
    cout << pos.size();
}
