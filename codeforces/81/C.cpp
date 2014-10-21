#include <bits/stdc++.h>
using namespace std;
bool srt(pair<int, int> i, pair<int, int> j) {
    if (i.first == j.first)
        return i.second > j.second;
    return i.first < j.first;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    pair<int, int> arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first, arr[i].second = i;
    if (a < b) {
        sort(arr, arr + n, srt);
        for (int i = 0; i < b; ++i)
            arr[i].first = 2, swap(arr[i].first, arr[i].second);
        for (int i = b; i < n; ++i)
            arr[i].first = 1, swap(arr[i].first, arr[i].second);
    } else if (a == b) {
        for (int i = 0; i < a; ++i)
            arr[i].first = 1, swap(arr[i].first, arr[i].second);
        for (int i = a; i < n; ++i)
            arr[i].first = 2, swap(arr[i].first, arr[i].second);
    } else {
        sort(arr, arr + n);
        for (int i = 0; i < a; ++i)
            arr[i].first = 1, swap(arr[i].first, arr[i].second);
        for (int i = a; i < n; ++i)
            arr[i].first = 2, swap(arr[i].first, arr[i].second);
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i)
        cout << arr[i].second << ' ';
}
