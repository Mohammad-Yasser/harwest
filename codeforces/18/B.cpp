#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long n, d, m, l, i;
    cin >> n >> d >> m >> l;
    for (i=d;i/m <=n-1 && i <= (i / m) * m + l;i =(i/m)*m+l+d-(((i/m)*m+l)%d))
        ;
    cout << i;
}
