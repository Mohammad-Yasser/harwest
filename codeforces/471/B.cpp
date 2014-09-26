#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first, arr[i].second = i;
    sort(arr, arr + n);
    vector<int> vec[3];
    int diff = 0;
    for (int i = 0; i < n; ++i)
        if (i + 1 < n && arr[i].first == arr[i + 1].first && diff - 2) {
            if (i + 2 < n && arr[i].first == arr[i + 2].first) {
                for (int ind = 0; ind < 3; ++ind)
                    for (int j = 0; j < 3; ++j)
                        vec[j].push_back(arr[i + (j + ind) % 3].second);
                diff = 2;
                i += 2;
            } else {
                for (int ind = 0; ind < 2; ++ind)
                    for (int j = 0; j < 3; ++j)
                        vec[j].push_back(
                                arr[i + ((diff >= j) ? ind : !ind)].second);
                i++, diff++;
            }
        } else
            for (int j = 0; j < 3; ++j)
                vec[j].push_back(arr[i].second);
    if (diff == 2) {
        cout << "YES\n";
        for (int i = 0; i < 3; cout << '\n', ++i)
            for (int j = 0; j < n; ++j)
                cout << vec[i][j] + 1 << ' ';
    } else
        cout << "NO";
}
