#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "qwertyuiopasdfghjkl;zxcvbnm,./", s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s2.size(); ++i)
        cout << s[s.find(s2[i]) - (s1 == "R") + (s1 == "L")];

}
