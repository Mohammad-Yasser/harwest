#include <bits/stdc++.h>

using namespace std;

vector<int> vec[100001];
int main() {
    ios_base::sync_with_stdio(0);
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; cin >> tmp, vec[tmp].push_back(i), ++i)
        ;
    for (int i = 0; i < 100001; sort(vec[i].begin(), vec[i].end()), ++i)
        ;
    n = 0;
    for (int in = 0; in < 100001; ++in)
        if (vec[in].size() == 1)
            vec[in][0] = 0, ++n;
        else if (vec[in].size()) {
            bool b = 1;
            for (int j = 2; j < (int) vec[in].size();
                    b &= vec[in][j] - vec[in][j - 1]
                            == vec[in][j - 1] - vec[in][j - 2], ++j)
                ;
            if (b)
                ++n, vec[in][0] = vec[in][1] - vec[in][0];
            else
                vec[in][0] = -1;
        }
    cout << n << '\n';
    for (int i = 0; i < 100001;
            (!vec[i].size() or vec[i][0] == -1) ? :
                                                    cout << i << ' '
                                                            << vec[i][0]
                                                            << '\n', ++i)
        ;

}
