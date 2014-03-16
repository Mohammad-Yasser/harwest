#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int k, a, b, v, s, boxes = 0;
    cin >> k >> a >> b >> v;
    s = a / v + (bool) (a % v);
    while (s > 0) {
        boxes++;
        if (b > 0) {
            s -= min(k, b + 1);
            b -= min(k-1, b);
        } else
            s--;
    }
    cout << boxes;

}
