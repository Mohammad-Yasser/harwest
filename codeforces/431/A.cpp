#include <bits/stdc++.h>
using namespace std;

int main() {


    long long sm=0 ;
    int a[4] ;
    cin >> a[0] >> a[1] >> a[2] >> a[3]  ;
    char c ;
    while (cin >> c)
        sm+=a[c-'0'-1] ;
    cout << sm ;

}
