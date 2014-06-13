#include <iostream>
using namespace std;

int n,m,k ;


int main() {
    
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k ;
    string s[n] ;
    for (int i=0;i<n;cin>>s[i++]) ;
    int tmp=0 ;
    for (int j=0;j<m;cout << tmp << ' ' ,tmp=0,++j)
    for (int i=0;i<n;++i)
    tmp+=(2*i<n && s[2*i][j]=='U')
                + (j-i>=0 && s[i][j-i]=='R') + (j+i<m && s[i][j+i]=='L');//cout << i << ' ' << j << ' ' << z << ' ' << pos[i][j][z] <<endl;

}