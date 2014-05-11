#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n,x, mx = 0;
    cin >> n >> x >> x ;
    int arr[n];
    for (int i = 0; i < n; cin >> arr[i++])
        ;
    for (int i = 0; i < n; ++i) {
        int sm = 0, tmp = x, l = i, r = i+1;
        bool b=1 ;
        while (l >= 0 or r < n) {
            int tsum=b ;
            for (; l >= 0 && arr[l] == tmp; ++tsum, --l)
                ;
            for (; r < n && arr[r] == tmp; ++tsum, ++r)
                ;
            if (tsum >= 3) {
                sm+=tsum ;
                if (l >= 0)
                    tmp = arr[l];
                if (r < n)
                    tmp = arr[r];
            } else
                break;
            b=0 ;
        }
        mx = max(mx, sm);

    }
    cout << max(--mx,0) ;
}
