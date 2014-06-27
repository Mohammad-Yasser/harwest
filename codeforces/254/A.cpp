#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, int> vec[600003];

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, m;
    cin >> n;
    for (int i = 1; i <= 2 * n;
            cin >> m, vec[m].first.push_back(i), vec[m].second++, ++i)
        ;
    for (int i = 0; i < 600003; ++i)
        if (vec[i].second % 2) {
            cout << -1;
            return 0;
        }
    for (int i = 0; i < 600003; ++i)
        for (int j = 0; j < vec[i].first.size(); j += 2)
            cout << vec[i].first[j] << ' ' << vec[i].first[j + 1] << '\n';
}
