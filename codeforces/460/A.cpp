#include <bits/stdc++.h>
using namespace std;

int main() {
    // @@#$ El-Kahraba @#@#$@#$
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int curr = n, prev = 1, tmp = 1;
    while (tmp) {
        tmp = 0;
        for (; prev <= curr; ++prev)
            tmp += !(prev % m);
        curr += tmp;
    }
    cout << curr;
}
