#include <bits/stdc++.h>
using namespace std;

bool arr[5003];

int main() {

    int n, tmp;
    cin >> n;

    while (cin >> tmp)
        arr[tmp] = 1;
    int ans = n;
    for (int i = 1; i <= n; ++i)
        ans -= arr[i];
    cout << ans;
}
