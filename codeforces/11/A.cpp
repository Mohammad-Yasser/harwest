#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n, d,s=0;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; cin >> arr[i], i++)
        ;
    for (int i = 1; i < n ; i++)
    {
        if (arr[i]<=arr[i-1])

        s+=(arr[i-1]-arr[i])/d + 1 ,
        arr[i]+=((arr[i-1]-arr[i])/d + 1)*d ;
    }
    cout << s ;
    return 0;
}
