#include <bits/stdc++.h>
using namespace std;

int arr[100005];

bool srt(int i, int j) {
    return arr[i] < arr[j];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int rm3 = 0;
    bool val = 0;
    vector<int> rem[3];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        rm3 = (rm3 + arr[i]) % 3;
        val |= !arr[i];
        rem[arr[i] % 3].push_back(i);
    }

    sort(rem[1].begin(), rem[1].end(), srt), sort(rem[2].begin(), rem[2].end(), srt);

    if (rm3 == 1) {
        if (rem[1].size())
            arr[rem[1][0]] = -1;
        else if (rem[2].size() >= 2)
            arr[rem[2][0]] = arr[rem[2][1]] = -1;
        else
            val = 0;
    }
    else if (rm3 == 2) {
        if (rem[2].size())
            arr[rem[2][0]] = -1;
        else if (rem[1].size() >= 2)
            arr[rem[1][0]] = arr[rem[1][1]] = -1;
        else
            val = 0;
    }

    if (!val) {
        cout << -1;
        return 0;
    }
    sort(arr, arr + n);
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] != -1 && (arr[i] or arr[n - 1] or !i or arr[i - 1]))
          cout << arr[i];
    }
}
