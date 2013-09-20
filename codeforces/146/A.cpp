//============================================================================
// Name        : 146A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
    int x,sum=0 ;
    cin >> x ;
    char y[x-1] ;
    cin >> y ;
    for (int i = 0 ; i<x ; i++)
    {
        if ((y[i]!='4') and (y[i]!='7'))
        {
            cout << "NO" ;
            return 0 ;
        }
        if (i<x/2)  sum+=y[i]-'0' ;
        else    sum-=y[i] - '0' ;

    }
    if (sum==0) cout << "YES" ;
    else cout << "NO" ;
}
