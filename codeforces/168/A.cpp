#include <iostream>
using namespace std;

int main() {
    int n,x,y ; cin >> n >> x >> y ;
    cout <<( y*n/100 + (bool)(y*n%100) -x < 0 ? 0 : y*n/100 + (bool)(y*n%100)-x );

}
