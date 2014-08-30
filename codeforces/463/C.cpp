#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    long long n, tmp, mx1 = 0, mx2 = 0;
    cin >> n;
    vector<long long> diag1(2 * n - 1), diag2(2 * n - 1), intrs[2 * n - 1];
    vector<pair<int, int> > ptint[2 * n - 1];
    pair<int, int> pt1, pt2;
    for (int i = 0; i < 2 * n - 1; ++i)
        intrs[i].resize(2 * n - 1), ptint[i].resize(2 * n - 1), fill(
                ptint[i].begin(), ptint[i].end(), make_pair(-1, -1));
    fill(diag1.begin(), diag1.end(), 0);
    fill(diag2.begin(), diag2.end(), 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            diag1[i + j] += tmp;
            diag2[n - 1 - j + i] += tmp;
            intrs[i + j][n - 1 - j + i] = tmp;
            ptint[i + j][n - 1 - j + i] = make_pair(i + 1, j + 1);
        }
    int i1 = -1, j1 = -1;
    for (int i = 0; i < 2 * n - 1; ++i)
        for (int j = 0; j < 2 * n - 1; ++j)
            if (diag1[i] + diag2[j] - intrs[i][j] >= mx1
                    && ptint[i][j].first != -1) {
                pt1 = ptint[i][j];
                mx1 = diag1[i] + diag2[j] - intrs[i][j];
                i1 = i;
                j1 = j;
            }
    for (int i = 0; i < 2 * n - 1; ++i)
        for (int j = 0; j < 2 * n - 1; ++j)
            if (diag1[i] + diag2[j] - intrs[i][j] >= mx2
                    && ptint[i][j].first != -1 && i != i1 && j != j1
                    && ptint[i][j1].first == -1 && ptint[i1][j].first == -1) {
                pt2 = ptint[i][j];
                mx2 = diag1[i] + diag2[j] - intrs[i][j];
            }
    cout << mx1 + mx2 << '\n';
    cout << pt1.first << ' ' << pt1.second << ' ' << pt2.first << ' '
            << pt2.second;
}
