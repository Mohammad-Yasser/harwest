#include <iostream>
using namespace std;

int main() {
    int n ; cin >> n ; int x=0,max=0,b ; n*=2 ;
    while (n--)
    {
        cin >> b ;
        if (n%2) x-=b ; else x+=b ;
        if (x>max) max=x ;
    }
    cout << max ;
}