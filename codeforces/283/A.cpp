#include <bits/stdc++.h>

using namespace std;

vector<int> vec(200001), vecpls(200001);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(7);
    int n, siz = 1, tmp, tmp2;
    long long sm = 0;
    cin >> n;
    while (cin >> n) {
        if (n == 3)
            sm -= vec[siz] + vecpls[siz], vecpls[siz - 1] += vecpls[siz], vecpls[siz] =
                    0, --siz;
        else if (n & 1)
            cin >> tmp >> tmp2, sm += tmp * tmp2, vecpls[tmp] += tmp2;
        else
            cin >> tmp, vec[++siz] = tmp, sm += tmp;
        cout << (double) sm / siz << '\n';
    }
}
