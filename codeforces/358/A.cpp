#include <bits/stdc++.h> 
using namespace std;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    bool b = 0;
    for (int i = 0; i + 1 < n; ++i)
        for (int j = 0; j + 1 < n; ++j)
            b |= min(arr[i], arr[i + 1]) < min(arr[j], arr[j + 1])
              && min(arr[j], arr[j + 1]) < max(arr[i], arr[i + 1])
              && max(arr[i], arr[i + 1]) < max(arr[j], arr[j + 1])
                ;
    cout << (b ? "yes" : "no");
}
