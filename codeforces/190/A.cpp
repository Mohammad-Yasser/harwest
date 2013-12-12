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
    int n , m ;
    cin >> n >> m ;
    if (n==0 && m==0) cout << "0 0" ;
    else if (n==0)cout << "Impossible" ;
    else
        cout <<max(m,n) << " " << n+m-(bool)m;

    return 0;
}
