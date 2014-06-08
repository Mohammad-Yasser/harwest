#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k,tmp;
    cin >> n >> k;
    set <int> ans ;
    for (int i=1;cin>>n;++i)
    {
        while (n--) {
            cin >> tmp ;
            if (tmp<k) ans.insert(i) ;
        }
    }
    cout << ans.size() << '\n' ;
    for (set<int>::iterator it=ans.begin();it!=ans.end();++it)
        cout << *it << ' ' ;

}
