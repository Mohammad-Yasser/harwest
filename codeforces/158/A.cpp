#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == a[k - 1] && a[k - 1] != 0 or a[i] > 0 && a[k - 1] == 0) {
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;

    return 0;
}
