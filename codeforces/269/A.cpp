#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[100005];
int n;
bool valid(long long k) {
    for (int i = 0; i < n; ++i)
        if (k <= arr[i].first
                or (k - arr[i].first) < 16
                        && round(pow(4, k - arr[i].first)) < arr[i].second)
            return 0;
    return 1;
}
int main() {

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    long long lw = 0, hg = 10e11, md;
    while (lw < hg) {
        md = (lw + hg) / 2;
        if (valid(md))
            hg = md;
        else
            lw = md + 1;
    }
    cout << lw;
}
