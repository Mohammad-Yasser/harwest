#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> angles;
    int x, y;
    cin >> x;
    while (cin >> x >> y) {
        double angle;
        if (!x)
            angle = 90 + 180 * (y < 0);
        else {
            angle = atan(fabs(y) / abs(x)) * 180 / acos(-1);
            if (x < 0 && y >= 0)
                angle = 180 - angle;
            else if (x < 0 && y < 0)
                angle += 180;
            else if (y < 0)
                angle = 360 - angle;
        }
        angles.push_back(angle);
    }
    sort(angles.begin(), angles.end());
    double ans = *angles.rbegin() - angles[0];
    for (int i = 1; i < angles.size(); ++i)
        ans = min(ans, 360 - angles[i] + angles[i - 1]);
    cout << fixed << setprecision(9) << ans;

}
