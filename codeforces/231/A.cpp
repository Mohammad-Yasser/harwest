//============================================================================
// Name        : 231A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
    int n,x=0 ; bool b,c,d ;
    cin >> n ;
    while (n--)
    {
        cin >> b >> c >> d;
        if (b==c) x+=b ; else x+=d ;
    }
    cout << x ;
}

