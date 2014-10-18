#include <bits/stdc++.h>
using namespace std;

int main() {

    int x, y;
    cin >> x;
    while (cin >> x >> y)
        if (x - y) {
            cout << "Happy Alex";
            return 0;
        }
    cout << "Poor Alex";

}
