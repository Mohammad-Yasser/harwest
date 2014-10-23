#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> angles;
    double x, y;
    cin >> x;
    while (cin >> x >> y)
        angles.push_back(atan2(y, x) * 180 / acos(-1));
    sort(angles.begin(), angles.end());
    double ans = *angles.rbegin() - angles[0];
    for (int i = 1; i < angles.size(); ++i)
        ans = min(ans, 360 - angles[i] + angles[i - 1]);
    cout << fixed << setprecision(9) << ans;

}
