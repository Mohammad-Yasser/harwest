#include <bits/stdc++.h>

using namespace std;

int main() {

    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;
    if (xp <= xv && yp <= yv or xp + yp <= max(xv, yv))
        cout << "Polycarp";
    else
        cout << "Vasiliy";
}
