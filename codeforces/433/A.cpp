#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[2] = { 0, 0 };
    while (cin >> n && 1+(arr[0] +=n == 100) && 1+(arr[1] += n == 200))
        ;
    if (arr[0] % 2 or arr[1] % 2 && arr[0] < 2)
        cout << "NO";
    else
        cout << "YES";
}
