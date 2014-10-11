#include <bits/stdc++.h>
using namespace std;

string s = string(3, 3);
long long fn(vector<long long> vec) {
    if (vec.size() == 1)
        return vec[0];
    vector<long long> tmp;
    long long mn = LLONG_MAX;
    for (long long i = 0; i < vec.size(); ++i)
        for (long long j = i + 1; j < vec.size(); ++j) {
            tmp.clear();
            if (s[4 - vec.size()] == '+')
                tmp.push_back(vec[i] + vec[j]);
            else
                tmp.push_back(vec[i] * vec[j]);
            for (long long ind = 0; ind < vec.size(); ++ind)
                if (ind != i && ind != j)
                    tmp.push_back(vec[ind]);
            mn = min(mn, fn(tmp));
        }
    return mn;
}

int main() {
    vector<long long> arr(4);
    for (long long i = 0; i < 4; ++i)
        cin >> arr[i];
    for (long long i = 0; i < 3; ++i)
        cin >> s[i];
    cout << fn(arr) << endl;
}
