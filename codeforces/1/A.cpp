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
    ll  n, m, k;
    cin >> n >> m >> k;

    cout << (n / k + (bool) (n % k)) * (m / k + (bool) (m % k));
    return 0;
}
