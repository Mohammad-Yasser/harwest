#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> a >> b;
    int q[a + b];
    for (int i = 0; i < a + b; cin >> q[i++])
        ;
    sort(q, q + a + b);
    cout << q[b] - q[b - 1];
}
