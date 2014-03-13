#include <bits/stdc++.h>


using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

int main() 
{ 
    int n ;
    cin >> n ;

    map <pii,int> v ;
    while (n--)
    {
        int x,y ;
        cin >> x >> y ;
        v[make_pair(x,y)] ++ ;
    }
    int mx=0 ;
    for (map<pii,int>::iterator it=v.begin() ; it!=v.end() ; ++it)
        if (it->second > mx) mx = it->second ;
    cout << mx ;






















































;


    return 0;
}