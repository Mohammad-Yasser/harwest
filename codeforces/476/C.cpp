#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod ((int)1e9+7)
int main() {

    ll a, b;
    cin >> a >> b;
    cout
            << ((((((b - 1) * b) / 2) % mod) * ((a * (a + 1) / 2) % mod) % mod)
                    * b % mod + ((((b - 1) * b / 2) % mod) * a) % mod) % mod;

}