#include <bits/stdc++.h>
using namespace std;
int main() {

    double n, k, t, s = 0;
    cin >> n >> k >> t;
    int i = 1;
    for (; t/100 >= (s + k) / (n * k); cout << k << ' ', s += k, ++i)
        ;
    if (i<=n)
    cout << int(t*n*k/100-s) << ' ';
    for (;i<n;cout<<"0 ",++i) ;
}
