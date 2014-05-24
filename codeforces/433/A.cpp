#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[2] = { 0, 0 };
    while (cin >> n)
        if (n == 100)
            arr[0]++;
        else
            arr[1]++;
    if (arr[1] % 2) {
        if (arr[0] >= 2 && arr[0] % 2 == 0)
            goto r;
        else
            goto n;
    } else if (arr[0] % 2)
        goto n;

    r: cout << "YES";
    return 0;
    n: cout << "NO";

}

// 100 2
