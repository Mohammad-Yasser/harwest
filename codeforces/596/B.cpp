#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    long long sum = 0,ans=0 ;

    while (n--) {
        int tmp ;
        cin >> tmp ;
        ans += abs(sum - tmp) ;
        sum = tmp ;
    }

    cout << ans ;

    return 0;
}
