#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    string s;
    cin >> n >> s >> s;
    if (s == "week")
        cout << 52 + (n == 5 or n == 6);
    else
        cout << 12 - (n == 30) - 5 * (n == 31);

}
