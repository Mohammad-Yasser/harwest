#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, tmp;
    cin >> n;
    string arr[n][2];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
        if (arr[i][1]<arr[i][0]) swap(arr[i][1],arr[i][0]) ;
    }
    string lst;
    while (cin >> tmp) {
        if (arr[tmp - 1][0] > lst)
            lst = arr[tmp - 1][0];
        else if (arr[tmp - 1][1] > lst)
            lst = arr[tmp - 1][1];
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" ;
}
